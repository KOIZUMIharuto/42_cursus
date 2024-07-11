/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:28:45 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/11 16:01:33 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	scale(t_map ***map, double ratio, bool rev)
{
	int	x;
	int	y;

	if (ratio == 0)
		return (false);
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			mult_vector(map[y][x]->isome, ratio, rev);
	}
	return (true);
}
