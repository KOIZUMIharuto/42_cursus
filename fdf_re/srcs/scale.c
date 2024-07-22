/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:28:45 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/22 11:42:35 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	scale(t_dot ***map, double ratio, bool rev)
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
			mult_vector(&map[y][x]->fixed, ratio, rev);
	}
	return (true);
}
