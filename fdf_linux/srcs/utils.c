/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:23:34 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/05 13:54:51 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	update_min_max(t_vector *vector, t_vector *min, t_vector *max);

bool	get_center(t_map ***map, t_vector *center)
{
	int			x_tmp;
	int			x_i;
	int			y_i;
	t_vector	min;
	t_vector	max;

	if (!center)
		return (false);
	y_i = -1;
	min = (t_vector){DBL_MAX, DBL_MAX, DBL_MAX, 0};
	max = (t_vector){-DBL_MAX, -DBL_MAX, -DBL_MAX, 0};
	while (map[++y_i])
	{
		x_i = -1;
		while (map[y_i][++x_i])
			update_min_max(map[y_i][x_i]->fixed, &min, &max);
		if (y_i != 0 && x_i != x_tmp)
			return (false);
		x_tmp = x_i;
	}
	*center = (t_vector){(max.x + min.x) / 2, (max.y + min.y) / 2,
		(max.z + min.z) / 2, 1};
	return (true);
}

static void	update_min_max(t_vector *vector, t_vector *min, t_vector *max)
{
	if (vector->x < min->x)
		min->x = vector->x;
	if (vector->x > max->x)
		max->x = vector->x;
	if (vector->y < min->y)
		min->y = vector->y;
	if (vector->y > max->y)
		max->y = vector->y;
	if (vector->z < min->z)
		min->z = vector->z;
	if (vector->z > max->z)
		max->z = vector->z;
}

double	rad(double deg)
{
	return (deg * M_PI / 180);
}
