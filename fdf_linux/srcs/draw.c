/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:33:25 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/08 14:54:33 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init_z_buffer(double **z_buf);
static bool	checker(t_vector p0, t_vector p1);
static void	draw_line(t_vars *vars, t_map *p0, t_map *p1);
static void	set_err(int *err, t_vector *tmp, t_vector *delta, t_vector *step);
static void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color);

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
				&& checker(*vars->map[y][x]->pos, *vars->map[y][x + 1]->pos))
				draw_line(vars, vars->map[y][x], vars->map[y][x + 1]);
			if (vars->map[y + 1]
				&& checker(*vars->map[y][x]->pos, *vars->map[y + 1][x]->pos))
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
		return (0 < p0.x && p0.x < WIDTH && 0);
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

static void	draw_line(t_vars *vars, t_map *p0, t_map *p1)
{
	t_vector	tmp;
	t_vector	delta;
	t_vector	step;
	int			err;

	tmp = (t_vector){p0->pos->x, p0->pos->y, p0->pos->z};
	delta = (t_vector){fabs(p1->pos->x - tmp.x), fabs(p1->pos->y - tmp.y), 0};
	step = (t_vector){2 * (tmp.x < p1->pos->x) - 1,
		2 * (tmp.y < p1->pos->y) - 1, 0};
	err = delta.x - delta.y;
	while (1)
	{
		if (0 <= tmp.x && tmp.x < WIDTH && 0 <= tmp.y && tmp.y < HEIGHT
			&& vars->z_buf[(int)tmp.y][(int)tmp.x] <= tmp.z)
		{
			my_mlx_pixel_put(&(vars->img),
				(int)round(tmp.x), (int)round(tmp.y), culc_color(p0, tmp, p1));
			vars->z_buf[(int)tmp.y][(int)tmp.x] = tmp.z;
		}
		if (fabs(tmp.x - p1->pos->x) <= 1 && fabs(tmp.y - p1->pos->y) <= 1)
			break ;
		set_err(&err, &tmp, &delta, &step);
	}
}

static void	set_err(int *err, t_vector *tmp, t_vector *delta, t_vector *step)
{
	int	e2;

	e2 = 2 * *err;
	if (e2 > -(delta->y))
	{
		*err -= (delta->y);
		tmp->x += step->x;
	}
	if (e2 < (delta->x))
	{
		*err += (delta->x);
		tmp->y += step->y;
	}
}

static void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	if (data->endian == 0)
		*(unsigned int *)dst = color;
	else
	{
		dst[0] = color / 0x1000000;
		dst[1] = (color / 0x10000) % 0x100;
		dst[2] = (color / 0x100) % 0x100;
		dst[3] = color % 0x100;
	}
}
