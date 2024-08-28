/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:28:45 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/27 11:53:42 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static bool	do_scale(t_map map, double ratio, int x, int y);

bool	scale(t_map map, double ratio, bool rev)
{
	int		x;
	int		y;

	if (ratio == 0)
		return (false);
	if (rev)
		ratio = 1 / ratio;
	y = -1;
	while (++y < map.y)
	{
		x = -1;
		while (++x < map.x)
		{
			if (!do_scale(map, ratio, x, y))
				return (return_msg_bool(ZOOM_CANCEL, 1));
		}
	}
	return (true);
}

static bool	do_scale(t_map map, double ratio, int x, int y)
{
	if (-(double)UINT_MAX / ratio < map.dots[y][x].fixed.x
		&& map.dots[y][x].fixed.x < (double)UINT_MAX / ratio
		&& -(double)UINT_MAX / ratio < map.dots[y][x].fixed.y
		&& map.dots[y][x].fixed.y < (double)UINT_MAX / ratio
		&& -(double)UINT_MAX / ratio < map.dots[y][x].fixed.z
		&& map.dots[y][x].fixed.z < (double)UINT_MAX / ratio)
	{
		mult_vector(&(map.dots[y][x].fixed), ratio, false);
		return (true);
	}
	while (y >= 0)
	{
		while (--x >= 0)
			mult_vector(&(map.dots[y][x].fixed), ratio, true);
		x = map.x;
		y--;
	}
	return (false);
}
