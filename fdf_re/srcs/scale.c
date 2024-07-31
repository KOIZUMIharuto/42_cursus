/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:28:45 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/31 11:55:33 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	scale(t_list *map, double ratio, bool rev)
{
	t_list	*row;
	t_dot	*dot;

	if (ratio == 0)
		return (false);
	while (map)
	{
		row = (t_list *)(map->content);
		while (row)
		{
			dot = (t_dot *)(row->content);
			mult_vector(&dot->fixed, ratio, rev);
			row = row->next;
		}
		map = map->next;
	}
	return (true);
}
