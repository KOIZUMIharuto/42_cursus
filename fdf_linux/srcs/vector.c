/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:25:28 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/11 16:01:33 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vector	*create_vector(double x, double y, double z)
{
	t_vector	*vector;

	vector = (t_vector *)ft_calloc(1, sizeof(t_vector));
	if (!vector)
		return (return_error_null(strerror(errno)));
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

void	copy_vector(t_map ***map, bool b_to_f)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (b_to_f)
			{
				map[y][x]->isome->x = map[y][x]->base->x;
				map[y][x]->isome->y = map[y][x]->base->y;
				map[y][x]->isome->z = map[y][x]->base->z;
			}
			else
			{
				map[y][x]->base->x = map[y][x]->isome->x;
				map[y][x]->base->y = map[y][x]->isome->y;
				map[y][x]->base->z = map[y][x]->isome->z;
			}
		}
	}
}
