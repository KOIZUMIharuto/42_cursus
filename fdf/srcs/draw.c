/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:33:25 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/28 12:51:53 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	init_z_buffer(double **z_buf);
static bool	checker(t_vector p0, t_vector p1);
static void	get_end_point_utils(t_vect_int *end_p, t_vector p0, double slope);

int	draw(t_vars *vars)
{
	int	x;
	int	y;

	ft_bzero(vars->img.addr, HEIGHT * vars->img.line_length);
	init_z_buffer(vars->z_buf);
	y = -1;
	while (++y < vars->map.y)
	{
		x = -1;
		while (++x < vars->map.x)
		{
			if (x + 1 < vars->map.x
				&& checker(vars->map.dots[y][x].fixed,
				vars->map.dots[y][x + 1].fixed))
				draw_line(vars, vars->map.dots[y][x], vars->map.dots[y][x + 1]);
			if (y + 1 < vars->map.y
				&& checker(vars->map.dots[y][x].fixed,
				vars->map.dots[y + 1][x].fixed))
				draw_line(vars, vars->map.dots[y][x], vars->map.dots[y + 1][x]);
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
	double	wid_intcpt;

	if ((0 <= floor(p0.x) && floor(p0.x) < WIDTH
			&& 0 <= floor(p0.y) && floor(p0.y) < HEIGHT)
		|| (0 <= p1.x && p1.x < WIDTH && 0 <= p1.y && p1.y < HEIGHT))
		return (true);
	if ((floor(p0.x) < 0 && floor(p1.x) < 0)
		|| (floor(p0.x) >= WIDTH && floor(p1.x) >= WIDTH)
		|| (floor(p0.y) < 0 && floor(p1.y) < 0)
		|| (floor(p0.y) >= HEIGHT && floor(p1.y) >= HEIGHT))
		return (false);
	if (floor(p0.x) == floor(p1.x))
		return (0 <= floor(p0.x) && floor(p0.x) < WIDTH);
	else if (floor(p0.y) == floor(p1.y))
		return (0 <= floor(p0.y) && floor(p0.y) < HEIGHT);
	else
	{
		slope = (floor(p1.y) - floor(p0.y)) / (floor(p1.x) - floor(p0.x));
		y_intcpt = floor(p0.y) - slope * floor(p0.x);
		wid_intcpt = slope * (WIDTH - 1) + y_intcpt;
		return ((slope >= 0 && y_intcpt < HEIGHT && wid_intcpt > 0)
			|| (slope < 0 && wid_intcpt < HEIGHT && y_intcpt > 0));
	}
}

void	get_end_point(t_vect_int *end_p, t_vector p0, t_vector p1)
{
	double	slope;

	if (0 <= floor(p0.x) && floor(p0.x) < WIDTH
		&& 0 <= floor(p0.y) && floor(p0.y) < HEIGHT)
		*end_p = (t_vect_int){(int)floor(p0.x), (int)floor(p0.y), 0};
	else
	{
		if (floor(p0.x) == floor(p1.x))
			*end_p = (t_vect_int){(int)floor(p0.x),
				(p0.y >= HEIGHT) * (HEIGHT - 1) * (p0.y >= 0), 0};
		else if (floor(p0.y) == floor(p1.y))
			*end_p = (t_vect_int){(p0.x >= WIDTH) * (WIDTH - 1) * (p0.x >= 0),
				(int)floor(p0.y), 0};
		else
		{
			slope = (floor(p1.y) - floor(p0.y)) / (floor(p1.x) - floor(p0.x));
			get_end_point_utils(end_p, p0, slope);
		}
	}
	end_p->z = (p0.z >= p1.z) * p0.z + (p0.z < p1.z) * p1.z;
}

static void	get_end_point_utils(t_vect_int *end_p, t_vector p0, double slope)
{
	long	y_intcpt;
	long	wid_intcpt;

	y_intcpt = (int)floor(p0.y - slope * p0.x);
	wid_intcpt = (int)floor(slope * WIDTH + y_intcpt);
	if ((WIDTH <= floor(p0.x) && 0 <= wid_intcpt && wid_intcpt < HEIGHT)
		|| (floor(p0.x) < 0 && 0 <= y_intcpt && y_intcpt < HEIGHT))
		*end_p = (t_vect_int){
			(WIDTH <= floor(p0.x)) * (WIDTH - 1) * (floor(p0.x) >= 0),
			(WIDTH <= floor(p0.x)) * wid_intcpt + (floor(p0.x) < 0) * y_intcpt,
			0};
	else
		*end_p = (t_vect_int){
			(HEIGHT <= floor(p0.y)) * (int)floor((HEIGHT - y_intcpt) / slope)
			+ (floor(p0.y) < 0) * (int)floor(-(y_intcpt / slope)),
			(HEIGHT <= floor(p0.y)) * (HEIGHT - 1) * (floor(p0.y) >= 0), 0};
}
