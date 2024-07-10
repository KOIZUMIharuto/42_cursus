/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:46:38 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/10 12:59:17 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	set_err(int *err, t_vector *tmp, t_vector *delta, t_vector *step);
static void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color);

void	draw_line(t_vars *vars, t_map *p0, t_map *p1)
{
	t_vector	tmp;
	t_vector	delta;
	t_vector	step;
	int			err;

	tmp = (t_vector){p0->fixed->x, p0->fixed->y, p0->fixed->z};
	delta = (t_vector){fabs(p1->fixed->x - tmp.x),
		fabs(p1->fixed->y - tmp.y), 0};
	step = (t_vector){2 * (tmp.x < p1->fixed->x) - 1,
		2 * (tmp.y < p1->fixed->y) - 1, 0};
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
