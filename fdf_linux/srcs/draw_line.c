/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:46:38 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/10 18:13:17 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	slope_over_1(t_vector_int *p0, int d_x, int d_y, int c);
static void	slope_under_1(t_vector_int *p0, int d_x, int d_y, int c);
static void	get_next_point(t_vector_int *p0, t_vector_int p1);
static void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color);

void	draw_line(t_vars *vars, t_map *p0, t_map *p1)
{
	t_end_points	end_ps;

	get_end_point(&(end_ps.p0), *(p0->fixed), *(p1->fixed));
	get_end_point(&(end_ps.p1), *(p1->fixed), *(p0->fixed));
	while (end_ps.p0.x != end_ps.p1.x || end_ps.p0.y != end_ps.p1.y)
	{
		my_mlx_pixel_put(&(vars->img), end_ps.p0.x,
			end_ps.p0.y, culc_color(p0, end_ps.p0, p1));
		get_next_point(&(end_ps.p0), end_ps.p1);
	}
}

static void	get_next_point(t_vector_int *p0, t_vector_int p1)
{
	int	d_x;
	int	d_y;
	int	c;

	d_x = p0->x - p1.x;
	d_y = p1.y - p0->y;
	c = -1 * (d_x * p0->y + d_y * p0->x);
	if (abs(d_x) < abs(d_y))
		slope_over_1(p0, d_x, d_y, c);
	else
		slope_under_1(p0, d_x, d_y, c);
}

static void	slope_over_1(t_vector_int *p0, int d_x, int d_y, int c)
{
	int	sign_y;
	int	sign_x;

	sign_y = 2 * (d_y > 0) - 1;
	sign_x = 2 * (d_x < 0) - 1;
	if ((d_x * (p0->y + sign_y * 2) + d_y * (p0->x + sign_x) + c) - (d_x * p0->y + d_y * p0->x + c) > 0)
		p0->x += sign_x;
	p0->y += sign_y;
}

static void	slope_under_1(t_vector_int *p0, int d_x, int d_y, int c)
{
	int	sign_y;
	int	sign_x;

	sign_y = 2 * (d_y > 0) - 1;
	sign_x = 2 * (d_x < 0) - 1;
	if ((d_x * (p0->y + sign_y) + d_y * (p0->x + sign_x * 2) + c) - (d_x * p0->y + d_y * p0->x + c) > 0)
		p0->y += sign_y;
	p0->x += sign_x;
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
