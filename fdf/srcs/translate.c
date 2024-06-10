/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:48:05 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/10 14:48:23 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	translate(t_map ***map, t_vector *vector, bool is_free, bool rev)
{
	int	x;
	int	y;
	int	dir;

	if (!vector)
		return (false);
	dir = 1 - 2 * (int)rev;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			map[y][x]->fixed->x += dir * vector->x;
			map[y][x]->fixed->y += dir * vector->y;
			map[y][x]->fixed->z += dir * vector->z;
		}
	}
	if (is_free)
		free(vector);
	return (true);
}
