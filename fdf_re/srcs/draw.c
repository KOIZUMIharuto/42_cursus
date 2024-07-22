/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:33:25 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/22 11:42:35 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init_z_buffer(double **z_buf);
static bool	checker(t_vector p0, t_vector p1);
static void	get_end_dot_utils(t_vect_int *end_p, t_vector p0, double slope);

int	draw(t_vars *vars)
{
	int	x;
	int	y;

	ft_bzero(vars->img.addr, HEIGHT * vars->img.line_length);
	init_z_buffer(vars->z_buf);
	y = -1;
	while (vars->map[++y])
	{
		x = -1;
		while (vars->map[y][++x])
		{
			if (vars->map[y][x + 1]
				&& checker(vars->map[y][x]->fixed,
				vars->map[y][x + 1]->fixed))
				draw_line(vars, vars->map[y][x], vars->map[y][x + 1]);
			if (vars->map[y + 1]
				&& checker(vars->map[y][x]->fixed,
				vars->map[y + 1][x]->fixed))
				draw_line(vars, vars->map[y][x], vars->map[y + 1][x]);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

static void	init_z_buffer(double **z_buf)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			z_buf[y][x] = -DBL_MAX;
	}
}

static bool	checker(t_vector p0, t_vector p1)
{
	double	slope;
	double	y_intcpt;
	double	width_intcpt;

	if ((0 <= p0.x && p0.x < WIDTH && 0 <= p0.y && p0.y < HEIGHT)
		|| (0 <= p1.x && p1.x < WIDTH && 0 <= p1.y && p1.y < HEIGHT))
		return (true);
	if ((p0.x < 0 && p1.x < 0) || (p0.x >= WIDTH && p1.x >= WIDTH)
		|| (p0.y < 0 && p1.y < 0) || (p0.y >= HEIGHT && p1.y >= HEIGHT))
		return (false);
	if (p0.x == p1.x)
		return (0 <= p0.x && p0.x < WIDTH);
	else if (p0.y == p1.y)
		return (0 <= p0.y && p0.y < HEIGHT);
	else
	{
		slope = (p1.y - p0.y) / (p1.x - p0.x);
		y_intcpt = p0.y - slope * p0.x;
		width_intcpt = slope * WIDTH + y_intcpt;
		return ((slope >= 0 && y_intcpt < HEIGHT && width_intcpt > 0)
			|| (slope < 0 && width_intcpt < HEIGHT && y_intcpt > 0));
	}
}

void	get_end_dot(t_vect_int *end_p, t_vector p0, t_vector p1)
{
	double	slope;

	if (0 <= p0.x && p0.x < WIDTH && 0 <= p0.y && p0.y < HEIGHT)
		*end_p = (t_vect_int){(int)round(p0.x), (int)round(p0.y), 0};
	else
	{
		if (p0.x == p1.x)
			*end_p = (t_vect_int){(int)round(p0.x),
				(p0.y >= HEIGHT) * (HEIGHT - 1) * (p0.y >= 0), 0};
		else if (p0.y == p1.y)
			*end_p = (t_vect_int){(p0.x >= WIDTH) * (WIDTH - 1) * (p0.x >= 0),
				(int)round(p0.y), 0};
		else
		{
			slope = (p1.y - p0.y) / (p1.x - p0.x);
			get_end_dot_utils(end_p, p0, slope);
		}
	}
	end_p->z = (p0.z >= p1.z) * p0.z + (p0.z < p1.z) * p1.z;
}

static void	get_end_dot_utils(t_vect_int *end_p, t_vector p0, double slope)
{
	int	y_intcpt;
	int	width_intcpt;

	y_intcpt = (int)round(p0.y - slope * p0.x);
	width_intcpt = (int)round(slope * WIDTH + y_intcpt);
	if ((WIDTH <= p0.x && 0 <= width_intcpt && width_intcpt < HEIGHT)
		|| (p0.x < 0 && 0 <= y_intcpt && y_intcpt < HEIGHT))
		*end_p = (t_vect_int){(WIDTH <= p0.x) * (WIDTH - 1) * (p0.x >= 0),
			(WIDTH <= p0.x) * width_intcpt + (p0.x < 0) * y_intcpt, 0};
	else
		*end_p = (t_vect_int){
			(HEIGHT <= p0.y) * (int)round((HEIGHT - y_intcpt) / slope)
			+ (p0.y < 0) * (int)round(-(y_intcpt / slope)),
			(HEIGHT <= p0.y) * (HEIGHT - 1) * (p0.y >= 0), 0};
}
