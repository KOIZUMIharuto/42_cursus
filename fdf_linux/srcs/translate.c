/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:48:05 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/10 12:13:27 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	trans(t_map ***map, t_vector *vector, bool is_free, bool rev)
{
	int			x;
	int			y;
	int			dir;
	t_vector	delta;

	if (!vector)
		return (false);
	dir = 1 - 2 * (int)rev;
	delta = (t_vector){dir * vector->x, dir * vector->y, dir * vector->z};
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			add_vector(map[y][x]->fixed, delta, true);
		}
	}
	if (is_free)
		free(vector);
	return (true);
}
