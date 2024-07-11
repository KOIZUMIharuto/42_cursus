/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:46:38 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/11 16:17:49 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	slope_over_1(t_vector_int *p0, int d_x, int d_y, int *e);
static void	slope_under_1(t_vector_int *p0, int d_x, int d_y, int *e);
static void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color);

void	draw_line(t_vars *vars, t_map *p0, t_map *p1)
{
	t_end_points	end_ps;
	int				d_x;
	int				d_y;
	int				e;

	get_end_point(&(end_ps.p0), *(p0->isome), *(p1->isome));
	get_end_point(&(end_ps.p1), *(p1->isome), *(p0->isome));
	d_x = end_ps.p1.x - end_ps.p0.x;
	d_y = end_ps.p1.y - end_ps.p0.y;
	e = 0;
	while (end_ps.p0.x != end_ps.p1.x || end_ps.p0.y != end_ps.p1.y)
	{
		if ((0 <= end_ps.p0.x && end_ps.p0.x < WIDTH
				&& 0 <= end_ps.p0.y && end_ps.p0.y < HEIGHT)
			&& end_ps.p0.z > vars->z_buf[end_ps.p0.y][end_ps.p0.x])
		{
			my_mlx_pixel_put(&(vars->img), end_ps.p0.x,
				end_ps.p0.y, culc_color(p0, end_ps.p0, p1));
			vars->z_buf[end_ps.p0.y][end_ps.p0.x] = end_ps.p0.z;
		}
		if (abs(d_x) <= abs(d_y))
			slope_over_1(&(end_ps.p0), d_x, d_y, &e);
		else
			slope_under_1(&(end_ps.p0), d_x, d_y, &e);
	}
}

static void	slope_over_1(t_vector_int *p0, int d_x, int d_y, int *e)
{
	int	sign_y;
	int	sign_x;

	sign_y = 2 * (d_y > 0) - 1;
	sign_x = 2 * (d_x > 0) - 1;
	p0->y += sign_y;
	*e += 2 * abs(d_x);
	if (*e > abs(d_y))
	{
		p0->x += sign_x;
		*e -= 2 * abs(d_y);
	}
}

static void	slope_under_1(t_vector_int *p0, int d_x, int d_y, int *e)
{
	int	sign_y;
	int	sign_x;

	sign_y = 2 * (d_y > 0) - 1;
	sign_x = 2 * (d_x > 0) - 1;
	p0->x += sign_x;
	*e += 2 * abs(d_y);
	if (*e > abs(d_x))
	{
		p0->y += sign_y;
		*e -= 2 * abs(d_x);
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
