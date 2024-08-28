/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:48:05 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/27 11:53:31 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static bool	do_trans(t_map map, t_vector vector, int x, int y);

bool	trans(t_map map, t_vector *vector, bool rev, char *cancel_msg)
{
	int			x;
	int			y;
	t_vector	delta;

	if (!vector)
		return (false);
	if (rev)
		delta = (t_vector){-vector->x, -vector->y, -vector->z};
	else
		delta = *vector;
	y = -1;
	while (++y < map.y)
	{
		x = -1;
		while (++x < map.x)
		{
			if (!do_trans(map, delta, x, y))
				return (return_msg_bool(cancel_msg, 1));
		}
	}
	return (true);
}

static bool	do_trans(t_map map, t_vector vector, int x, int y)
{
	if (-(double)UINT_MAX - vector.x < map.dots[y][x].fixed.x
		&& map.dots[y][x].fixed.x < (double)UINT_MAX - vector.x
		&& -(double)UINT_MAX - vector.y < map.dots[y][x].fixed.y
		&& map.dots[y][x].fixed.y < (double)UINT_MAX - vector.y
		&& -(double)UINT_MAX - vector.z < map.dots[y][x].fixed.z
		&& map.dots[y][x].fixed.z < (double)UINT_MAX - vector.z)
	{
		add_vector(&(map.dots[y][x].fixed), vector, true);
		return (true);
	}
	while (y >= 0)
	{
		while (--x >= 0)
			add_vector(&(map.dots[y][x].fixed), vector, false);
		x = map.x;
		y--;
	}
	return (false);
}
