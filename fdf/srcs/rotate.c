/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:46:08 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/10 14:46:34 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	rotate_z(t_vector *vector, double angle);
static void	rotate_y(t_vector *vector, double angle);
static void	rotate_x(t_vector *vector, double angle);

bool	rotate(t_map ***map, t_vector *vector, bool is_free, bool rev)
{
	int		x;
	int		y;

	if (!vector)
		return (false);
	if (rev)
	{
		vector->x *= -1;
		vector->y *= -1;
		vector->z *= -1;
	}
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			rotate_z(map[y][x]->fixed, vector->z);
			rotate_y(map[y][x]->fixed, vector->y);
			rotate_x(map[y][x]->fixed, vector->x);
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

	tmp_x = vector->x;
	tmp_y = vector->y;
	vector->x = tmp_x * cos(angle) - tmp_y * sin(angle);
	vector->y = tmp_x * sin(angle) + tmp_y * cos(angle);
}

static void	rotate_y(t_vector *vector, double angle)
{
	double	tmp_x;
	double	tmp_z;

	tmp_x = vector->x;
	tmp_z = vector->z;
	vector->x = tmp_x * cos(angle) + tmp_z * sin(angle);
	vector->z = -tmp_x * sin(angle) + tmp_z * cos(angle);
}

static void	rotate_x(t_vector *vector, double angle)
{
	double	tmp_y;
	double	tmp_z;

	tmp_y = vector->y;
	tmp_z = vector->z;
	vector->y = tmp_y * cos(angle) - tmp_z * sin(angle);
	vector->z = tmp_y * sin(angle) + tmp_z * cos(angle);
}

