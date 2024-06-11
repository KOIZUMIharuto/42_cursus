/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:28:45 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/11 12:19:16 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	scale(t_map ***map, double ratio, bool rev)
{
	int		x;
	int		y;
	double	fixed_ratio;

	if (ratio == 0)
		return (false);
	fixed_ratio = ratio * (1 - (double)rev) + 1 / ratio * (double)rev;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			map[y][x]->fixed->x *= fixed_ratio;
			map[y][x]->fixed->y *= fixed_ratio;
			map[y][x]->fixed->z *= fixed_ratio;
		}
	}
	return (true);
}
