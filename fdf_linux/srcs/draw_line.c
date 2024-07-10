/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:46:38 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/10 15:06:59 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	get_end_point(t_vector_int *end_p, t_vector p0, t_vector p1);
static void	get_end_point_utils(t_vector_int *end_p, t_vector p0, double slope);
static void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color);

void	draw_line(t_vars *vars, t_map *p0, t_map *p1)
{
	t_end_points	end_points;

	get_end_point(&(end_points.p0), *(p0->fixed), *(p1->fixed));
	get_end_point(&(end_points.p1), *(p1->fixed), *(p0->fixed));
	if (p0->fixed->z >= p1->fixed->z)
		end_points.z = p0->fixed->z;
	else
		end_points.z = p1->fixed->z;
	(void)vars;
}

static void	get_end_point(t_vector_int *end_p, t_vector p0, t_vector p1)
{
	double	slope;

	if (0 <= p0.x && p0.x < WIDTH && 0 <= p0.y && p0.y < HEIGHT)
		*end_p = (t_vector_int){(int)round(p0.x), (int)round(p0.y)};
	else
	{
		if (p0.x == p1.x)
			*end_p = (t_vector_int){(int)round(p0.x),
				(p0.y > HEIGHT) * HEIGHT * (p0.y >= 0)};
		else if (p0.y == p1.y)
			*end_p = (t_vector_int){(p0.x > WIDTH) * WIDTH * (p0.x >= 0),
				(int)round(p0.y)};
		else
		{
			slope = (p1.y - p0.y) / (p1.x - p0.x);
			get_end_point_utils(end_p, p0, slope);
		}
	}
}

static void	get_end_point_utils(t_vector_int *end_p, t_vector p0, double slope)
{
	int		y_intcpt;
	int		width_intcpt;

	y_intcpt = (int)round(p0.y - slope * p0.x);
	width_intcpt = (int)round(slope * WIDTH + y_intcpt);
	if ((WIDTH <= p0.x && 0 <= width_intcpt && width_intcpt < HEIGHT)
		|| (p0.x < 0 && 0 <= y_intcpt && y_intcpt < HEIGHT))
		*end_p = (t_vector_int){(WIDTH <= p0.x) * WIDTH * (p0.x >= 0),
			(WIDTH <= p0.x) * width_intcpt + (p0.x < 0) * y_intcpt};
	else
		*end_p = (t_vector_int){
			(HEIGHT <= p0.y) * (int)round((HEIGHT - y_intcpt) / slope)
			+ (p0.y < 0) * (int)round(-(y_intcpt / slope)),
			(HEIGHT <= p0.y) * HEIGHT * (p0.y >= 0)};
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
