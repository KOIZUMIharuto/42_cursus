/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:46:08 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/27 11:53:52 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static bool	do_rotate(t_map map, t_vector *vector, int x, int y);
static bool	rotate_z(t_vector *vector, double angle);
static bool	rotate_y(t_vector *vector, double angle);
static bool	rotate_x(t_vector *vector, double angle);

bool	rotate(t_map map, t_vector *vector, bool rev)
{
	int		x;
	int		y;

	if (!vector)
		return (false);
	if (rev)
		*vector = (t_vector){-vector->x, -vector->y, -vector->z};
	y = -1;
	while (++y < map.y)
	{
		x = -1;
		while (++x < map.x)
		{
			if (!do_rotate(map, vector, x, y))
				return (return_msg_bool(ROTATE_CANCEL, 1));
		}
	}
	return (true);
}

static bool	do_rotate(t_map map, t_vector *vector, int x, int y)
{
	int	do_cancel;

	do_cancel = 0;
	if (rotate_z(&(map.dots[y][x].fixed), vector->z) && ++do_cancel
		&& rotate_y(&(map.dots[y][x].fixed), vector->y) && ++do_cancel
		&& rotate_x(&(map.dots[y][x].fixed), vector->x))
		return (true);
	while (y >= 0)
	{
		while (x >= 0)
		{
			if (do_cancel > 2)
				rotate_x(&(map.dots[y][x].fixed), -vector->x);
			if (do_cancel > 1)
				rotate_y(&(map.dots[y][x].fixed), -vector->y);
			if (do_cancel > 0)
				rotate_z(&(map.dots[y][x].fixed), -vector->z);
			do_cancel = 3;
			x--;
		}
		x = map.x - 1;
		y--;
	}
	return (false);
}

static bool	rotate_z(t_vector *vector, double angle)
{
	double	cos_a;
	double	sin_a;
	double	tmp_x;
	double	tmp_y;

	if (angle == 0)
		return (true);
	cos_a = cos(angle);
	sin_a = sin(angle);
	tmp_x = vector->x;
	tmp_y = vector->y;
	if (tmp_x * cos_a < - (double)UINT_MAX + tmp_y * sin_a
		|| (double)UINT_MAX + tmp_y * sin_a < tmp_x * cos_a
		|| tmp_x * sin_a < - (double)UINT_MAX - tmp_y * cos_a
		|| (double)UINT_MAX - tmp_y * cos_a < tmp_x * sin_a)
		return (false);
	vector->x = tmp_x * cos_a + (-tmp_y * sin_a);
	vector->y = tmp_x * sin_a + tmp_y * cos_a;
	return (true);
}

static bool	rotate_y(t_vector *vector, double angle)
{
	double	cos_a;
	double	sin_a;
	double	tmp_x;
	double	tmp_z;

	if (angle == 0)
		return (true);
	cos_a = cos(angle);
	sin_a = sin(angle);
	tmp_x = vector->x;
	tmp_z = vector->z;
	if (tmp_x * cos_a < -(double)UINT_MAX - tmp_z * sin_a
		|| (double)UINT_MAX - tmp_z * sin_a < tmp_x * cos_a
		|| - tmp_x * sin_a < -(double)UINT_MAX - tmp_z * cos_a
		|| (double)UINT_MAX - tmp_z * cos_a < -tmp_x * sin_a)
		return (false);
	vector->x = tmp_x * cos_a + tmp_z * sin_a;
	vector->z = -tmp_x * sin_a + tmp_z * cos_a;
	return (true);
}

static bool	rotate_x(t_vector *vector, double angle)
{
	double	cos_a;
	double	sin_a;
	double	tmp_y;
	double	tmp_z;

	if (angle == 0)
		return (true);
	cos_a = cos(angle);
	sin_a = sin(angle);
	tmp_y = vector->y;
	tmp_z = vector->z;
	if (tmp_y * cos_a < - (double)UINT_MAX + tmp_z * sin_a
		|| (double)UINT_MAX + tmp_z * sin_a < tmp_y * cos_a
		|| tmp_y * sin_a < - (double)UINT_MAX - tmp_z * cos_a
		|| (double)UINT_MAX - tmp_z * cos_a < tmp_y * sin_a)
		return (false);
	vector->y = tmp_y * cos_a - tmp_z * sin_a;
	vector->z = tmp_y * sin_a + tmp_z * cos_a;
	return (true);
}
