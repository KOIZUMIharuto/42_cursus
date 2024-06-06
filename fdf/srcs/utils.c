/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:23:34 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/07 00:23:33 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	get_center(t_data ***data, t_vector4 *center)
{
	int		x_tmp;
	double	z_min_tmp;
	double	z_max_tmp;

	if (!center)
		return (false);
	z_min_tmp = INT_MAX;
	z_max_tmp = INT_MIN;
	while (data[(int)center->y])
	{
		x_tmp = 0;
		while (data[(int)center->y][x_tmp])
		{
			if (data[(int)center->y][x_tmp]->base->z < z_min_tmp)
				z_min_tmp = data[(int)center->y][x_tmp]->base->z;
			if (data[(int)center->y][x_tmp]->base->z > z_max_tmp)
				z_max_tmp = data[(int)center->y][x_tmp]->base->z;
			x_tmp++;
		}
		if (center->y != 0 && x_tmp != (int)center->x)
			return (false);
		center->x = x_tmp;
		center->y++;
	}
	center->x = (center->x - 1) / 2;
	center->y = (center->y - 1) / 2;
	center->z = (z_max_tmp + z_min_tmp) / 2;
	printf("center(%.2F, %.2F, %.2F)\n", center->x, center->y, center->z);
	return (true);
}

double	rad(double deg)
{
	return (deg * M_PI / 180);
}