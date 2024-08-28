/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:25:28 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/21 15:43:29 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_vector	*create_vector(double x, double y, double z)
{
	t_vector	*vector;

	vector = (t_vector *)ft_calloc(1, sizeof(t_vector));
	if (!vector)
		return (return_msg_null(strerror(errno), 2));
	*vector = (t_vector){x, y, z};
	return (vector);
}

void	add_vector(t_vector *src, t_vector add, bool sign)
{
	src->x += (2 * sign - 1) * add.x;
	src->y += (2 * sign - 1) * add.y;
	src->z += (2 * sign - 1) * add.z;
}

void	mult_vector(t_vector *src, double ratio, bool rev)
{
	if (!rev)
	{
		src->x *= ratio;
		src->y *= ratio;
		src->z *= ratio;
	}
	else
	{
		src->x /= ratio;
		src->y /= ratio;
		src->z /= ratio;
	}
}

void	copy_vector(t_map map, bool b_to_f)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map.y)
	{
		x = -1;
		while (++x < map.x)
		{
			if (b_to_f)
			{
				map.dots[y][x].fixed.x = map.dots[y][x].base.x;
				map.dots[y][x].fixed.y = map.dots[y][x].base.y;
				map.dots[y][x].fixed.z = map.dots[y][x].base.z;
			}
			else
			{
				map.dots[y][x].base.x = map.dots[y][x].fixed.x;
				map.dots[y][x].base.y = map.dots[y][x].fixed.y;
				map.dots[y][x].base.z = map.dots[y][x].fixed.z;
			}
		}
	}
}
