/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:33:25 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/13 15:59:40 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// static void	init_z_buffer(double **z_buf);
static void	draw_line(t_vars *vars, t_map *p0, t_map *p1);
static void	set_err(int *err, t_vector *tmp, t_vector *delta, t_vector *step);
static void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color);

int	draw(t_vars *vars)
{
	int	x;
	int	y;

	ft_memset(vars->img.addr, 0, HEIGHT * vars->img.line_length);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			vars->z_buf[y][x] = -DBL_MAX;
	}
	y = -1;
	while (vars->map[++y])
	{
		x = -1;
		while (vars->map[y][++x])
		{
			if (vars->map[y][x + 1])
				draw_line(vars, vars->map[y][x], vars->map[y][x + 1]);
			if (vars->map[y + 1] && vars->map[y + 1][x])
				draw_line(vars, vars->map[y][x], vars->map[y + 1][x]);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

static void	draw_line(t_vars *vars, t_map *p0, t_map *p1)
{
	t_vector	tmp;
	t_vector	delta;
	t_vector	step;
	int			err;

	tmp = (t_vector){p0->fixed->x, p0->fixed->y, p0->fixed->z, 1};
	delta = (t_vector){fabs(p1->fixed->x - tmp.x),
		fabs(p1->fixed->y - tmp.y), 0, 0};
	step = (t_vector){2 * (tmp.x < p1->fixed->x) - 1,
		2 * (tmp.y < p1->fixed->y) - 1, 0, 0};
	err = delta.x - delta.y;
	while (1)
	{
		if (0 <= tmp.x && tmp.x < WIDTH && 0 <= tmp.y && tmp.y < HEIGHT
			&& vars->z_buf[(int)tmp.y][(int)tmp.x] <= tmp.z)
		{
			my_mlx_pixel_put(&(vars->img),
				tmp.x, tmp.y, get_color(p0, tmp, p1));
			vars->z_buf[(int)tmp.y][(int)tmp.x] = tmp.z;
		}
		if (fabs(tmp.x - p1->fixed->x) <= 1 && fabs(tmp.y - p1->fixed->y) <= 1)
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
	*(unsigned int *)dst = color;
}
