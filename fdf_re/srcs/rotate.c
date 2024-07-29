/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:46:08 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/29 16:11:19 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	rotate_z(t_vector *vector, double angle);
static void	rotate_y(t_vector *vector, double angle);
static void	rotate_x(t_vector *vector, double angle);

void	rotate(t_list *map, t_vector *vector, bool rev)
{
	t_list	*row;
	t_dot	*dot;

	if (rev)
		*vector = (t_vector){-vector->x, -vector->y, -vector->z};
	while (map)
	{
		row = (t_list *)(map->content);
		while (row)
		{
			dot = (t_dot *)(row->content);
			rotate_z(&dot->fixed, vector->z);
			rotate_y(&dot->fixed, vector->y);
			rotate_x(&dot->fixed, vector->x);
			row = row->next;
		}
		map = map->next;
	}
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
