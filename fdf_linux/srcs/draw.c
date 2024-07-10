/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:33:25 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/10 12:51:07 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init_z_buffer(double **z_buf);
static bool	checker(t_vector p0, t_vector p1);

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
				&& checker(*vars->map[y][x]->fixed,
				*vars->map[y][x + 1]->fixed))
				draw_line(vars, vars->map[y][x], vars->map[y][x + 1]);
			if (vars->map[y + 1]
				&& checker(*vars->map[y][x]->fixed,
				*vars->map[y + 1][x]->fixed))
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
	double	x_intcpt;
	double	width_intcpt;

	if ((0 < p0.x && p0.x < WIDTH && 0 < p0.y && p0.y < HEIGHT)
		|| (0 < p1.x && p1.x < WIDTH && 0 < p1.y && p1.y < HEIGHT))
		return (true);
	if ((p0.x < 0 && p1.x < 0) || (p0.x > WIDTH && p1.x > WIDTH)
		|| (p0.y < 0 && p1.y < 0) || (p0.y > HEIGHT && p1.y > HEIGHT))
		return (false);
	if (p0.x == p1.x)
		return (0 < p0.x && p0.x < WIDTH);
	else
	{
		slope = (p1.y - p0.y) / (p1.x - p0.x);
		y_intcpt = p0.y - slope * p0.x;
		x_intcpt = -(y_intcpt / slope);
		width_intcpt = slope * WIDTH + y_intcpt;
		return ((slope >= 0 && y_intcpt < HEIGHT && x_intcpt < WIDTH)
			|| (slope < 0 && width_intcpt < HEIGHT && x_intcpt > 0));
	}
}
