/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:33:25 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/10 15:26:11 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init_z_buffer(double **z_buffer);
static void	draw_line(t_vars *vars, t_map *p0, t_map *p1);
static void	set_err(int *err, t_vector *tmp, t_vector *delta, t_vector *step);
static void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color);

int	draw(t_vars *vars)
{
	int	x;
	int	y;

	ft_memset(vars->img.addr, 0, HEIGHT * vars->img.line_length);
	init_z_buffer(vars->z_buffer);
	x = -1;
	while (vars->map[++x])
	{
		y = -1;
		while (vars->map[x][++y])
		{
			if (vars->map[x][y + 1])
				draw_line(vars, vars->map[x][y], vars->map[x][y + 1]);
			if (vars->map[x + 1] && vars->map[x + 1][y])
				draw_line(vars, vars->map[x][y], vars->map[x + 1][y]);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

static void	init_z_buffer(double **z_buffer)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			z_buffer[y][x] = -DBL_MAX;
	}
}

static void	draw_line(t_vars *vars, t_map *p0, t_map *p1)
{
	t_vector	tmp;
	t_vector	delta;
	t_vector	step;
	int			err;

	tmp = (t_vector){p0->fixed->x, p0->fixed->y, p0->fixed->z, 1};
	if ((tmp.x < 0 || tmp.x >= WIDTH || tmp.y < 0 || tmp.y >= HEIGHT)
		&& (p1->fixed->x < 0 || p1->fixed->x >= WIDTH
			|| p1->fixed->y < 0 || p1->fixed->y >= HEIGHT))
		return ;
	delta = (t_vector){fabs(p1->fixed->x - tmp.x),
		fabs(p1->fixed->y - tmp.y), 0, 0};
	step = (t_vector){2 * (tmp.x < p1->fixed->x) - 1,
		2 * (tmp.y < p1->fixed->y) - 1, 0, 0};
	err = delta.x - delta.y;
	while (1)
	{
		if (0 <= (int)tmp.x && (int)tmp.x < WIDTH
			&& 0 <= (int)tmp.y && (int)tmp.y < HEIGHT
			&& vars->z_buffer[(int)tmp.y][(int)tmp.x] <= tmp.z)
		{
			my_mlx_pixel_put(&(vars->img), tmp.x, tmp.y, p0->color);
			vars->z_buffer[(int)tmp.y][(int)tmp.x] = tmp.z;
		}
		if (fabs(tmp.x - p1->fixed->x) < 1 && fabs(tmp.y - p1->fixed->y) < 1)
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
