/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:46:08 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/11 16:01:33 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	rotate_z(t_vector *vector, double angle);
static void	rotate_y(t_vector *vector, double angle);
static void	rotate_x(t_vector *vector, double angle);

bool	rotate(t_map ***map, t_vector *vector, bool is_free, bool rev)
{
	int	x;
	int	y;

	if (!vector)
		return (false);
	if (rev)
		*vector = (t_vector){-vector->x, -vector->y, -vector->z};
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			rotate_z(map[y][x]->isome, vector->z);
			rotate_y(map[y][x]->isome, vector->y);
			rotate_x(map[y][x]->isome, vector->x);
		}
	}
	if (is_free)
		free(vector);
	return (true);
}

static void	rotate_z(t_vector *vector, double angle)
{
	double	tmp_x;
	double	tmp_y;

	if (angle == 0)
		return ;
	tmp_x = vector->x;
	tmp_y = vector->y;
	vector->x = tmp_x * cos(angle) - tmp_y * sin(angle);
	vector->y = tmp_x * sin(angle) + tmp_y * cos(angle);
}

static void	rotate_y(t_vector *vector, double angle)
{
	double	tmp_x;
	double	tmp_z;

	if (angle == 0)
		return ;
	tmp_x = vector->x;
	tmp_z = vector->z;
	vector->x = tmp_x * cos(angle) + tmp_z * sin(angle);
	vector->z = -tmp_x * sin(angle) + tmp_z * cos(angle);
}

static void	rotate_x(t_vector *vector, double angle)
{
	double	tmp_y;
	double	tmp_z;

	if (angle == 0)
		return ;
	tmp_y = vector->y;
	tmp_z = vector->z;
	vector->y = tmp_y * cos(angle) - tmp_z * sin(angle);
	vector->z = tmp_y * sin(angle) + tmp_z * cos(angle);
}
