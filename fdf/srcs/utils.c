/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:23:34 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/11 16:10:22 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	get_center(t_map ***map, t_vector *center)
{
	int		x_tmp;
	double	z_min_tmp;
	double	z_max_tmp;

	if (!center)
		return (false);
	z_min_tmp = DBL_MAX;
	z_max_tmp = -DBL_MAX;
	while (map[(int)(++center->y)])
	{
		x_tmp = -1;
		while (map[(int)center->y][++x_tmp])
		{
			if (map[(int)center->y][x_tmp]->base->z < z_min_tmp)
				z_min_tmp = map[(int)center->y][x_tmp]->base->z;
			if (map[(int)center->y][x_tmp]->base->z > z_max_tmp)
				z_max_tmp = map[(int)center->y][x_tmp]->base->z;
		}
		if (center->y != 0 && x_tmp != (int)center->x)
			return (false);
		center->x = (double)x_tmp;
	}
	*center = (t_vector){(center->x - 1) / 2, (center->y - 1) / 2,
		(z_max_tmp + z_min_tmp) / 2, 1};
	return (true);
}

double	rad(double deg)
{
	return (deg * M_PI / 180);
}
