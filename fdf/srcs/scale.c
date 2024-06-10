/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:28:45 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/10 14:48:40 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	scale(t_map ***map, t_vector *vector, bool is_free, bool rev)
{
	int		x;
	int		y;
	double	scale_x;
	double	scale_y;
	double	scale_z;

	if (!vector)
		return (false);
	scale_x = vector->x * (1 - (int)rev) + 1 / vector->x * (int)rev;
	scale_y = vector->y * (1 - (int)rev) + 1 / vector->y * (int)rev;
	scale_z = vector->z * (1 - (int)rev) + 1 / vector->z * (int)rev;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			map[y][x]->fixed->x *= scale_x;
			map[y][x]->fixed->y *= scale_y;
			map[y][x]->fixed->z *= scale_z;
		}
	}
	if (is_free)
		free(vector);
	return (true);
}
