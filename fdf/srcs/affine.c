/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:28:45 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/05 16:54:17 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	translate(t_data ***data, t_vector4 *vector, bool need_free)
{
	int	x;
	int	y;

	if (!data || !vector)
		return (false);
	y = 0;
	while (data[y])
	{
		x = 0;
		while (data[y][x])
		{
			data[y][x]->fixed->x = data[y][x]->origin->x + vector->x;
			data[y][x]->fixed->y = data[y][x]->origin->y + vector->y;
			data[y][x]->fixed->z = data[y][x]->origin->z + vector->z;
			x++;
		}
		y++;
	}
	if (need_free)
		free_vector(vector);
	return (true);
}

bool	scale(t_data ***data, t_vector4 *vector, bool need_free)
{
	int	x;
	int	y;

	if (!data || !vector)
		return (false);
	y = 0;
	while (data[y])
	{
		x = 0;
		while (data[y][x])
		{
			data[y][x]->fixed->x = data[y][x]->origin->x * vector->x;
			data[y][x]->fixed->y = data[y][x]->origin->y * vector->y;
			data[y][x]->fixed->z = data[y][x]->origin->z * vector->z;
			x++;
		}
		y++;
	}
	if (need_free)
		free_vector(vector);
	return (true);
}

bool	rotate(t_data ***data, t_vector4 *vector, bool need_free)
{

}
