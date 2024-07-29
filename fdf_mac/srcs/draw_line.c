/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:46:38 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/29 14:49:32 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	get_end_dot(t_vect_int *end_p, t_vector p0, t_vector p1);
static void	get_end_dot_utils(t_vect_int *end_p, t_vector p0, double slope);
static void	get_next_dot(t_vect_int *p0, t_vect_int delta, int *e);
static void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color);

void	draw_line(t_vars *vars, t_dot *p0, t_dot *p1)
{
	t_end_dots	end_ps;
	t_vect_int	delta;
	int			e;

	get_end_dot(&(end_ps.p0), p0->fixed, p1->fixed);
	get_end_dot(&(end_ps.p1), p1->fixed, p0->fixed);
	delta.x = end_ps.p1.x - end_ps.p0.x;
	delta.y = end_ps.p1.y - end_ps.p0.y;
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
		get_next_dot(&(end_ps.p0), delta, &e);
	}
}

static void	get_end_dot(t_vect_int *end_p, t_vector p0, t_vector p1)
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


static void	get_next_dot(t_vect_int *p0, t_vect_int delta, int *e)
{
	if (abs(delta.x) <= abs(delta.y))
	{
		p0->y += 2 * (delta.y > 0) - 1;
		*e += 2 * abs(delta.x);
		if (*e > abs(delta.y))
		{
			p0->x += 2 * (delta.x > 0) - 1;
			*e -= 2 * abs(delta.y);
		}
	}
	else
	{
		p0->x += 2 * (delta.x > 0) - 1;
		*e += 2 * abs(delta.y);
		if (*e > abs(delta.x))
		{
			p0->y += 2 * (delta.y > 0) - 1;
			*e -= 2 * abs(delta.x);
		}
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
