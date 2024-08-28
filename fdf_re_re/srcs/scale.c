/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:28:45 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/19 15:33:06 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <fdf.h>

bool	scale(t_map map, double ratio, bool rev)
{
	int	x;
	int	y;

	if (ratio == 0)
		return (false);
	y = -1;
	while (++y < map.y)
	{
		x = -1;
		while (++x < map.x)
			mult_vector(&(map.dots[y][x].fixed), ratio, rev);
	}
	return (true);
}