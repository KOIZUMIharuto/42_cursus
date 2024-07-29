/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:25:28 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/29 16:11:40 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	add_vector(t_vector *src, t_vector add, bool sign)
{
	src->x += (2 * sign - 1) * add.x;
	src->y += (2 * sign - 1) * add.y;
	src->z += (2 * sign - 1) * add.z;
}

void	mult_vector(t_vector *src, double ratio, bool rev)
{
	if (!rev)
	{
		src->x *= ratio;
		src->y *= ratio;
		src->z *= ratio;
	}
	else
	{
		src->x /= ratio;
		src->y /= ratio;
		src->z /= ratio;
	}
}

void	copy_vector(t_list *map, bool b_to_f)
{
	t_list	*row;
	t_dot	*dot;

	while (map)
	{
		row = (t_list *)(map->content);
		while (row)
		{
			dot = (t_dot *)(row->content);
			if (b_to_f)
				dot->fixed = (t_vector){
					dot->base.x,
					dot->base.y,
					dot->base.z};
			else
				dot->base = (t_vector){
					dot->fixed.x,
					dot->fixed.y,
					dot->fixed.z};
			row = row->next;
		}
		map = map->next;
	}
}
