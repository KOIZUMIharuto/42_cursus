/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:48:05 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/31 13:01:51 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	trans(t_list *map, t_vector *vector, bool rev)
{
	t_list	*row;
	t_dot	*dot;

	while (map)
	{
		row = (t_list *)(map->content);
		while (row)
		{
			dot = (t_dot *)(row->content);
			add_vector(&dot->fixed, *vector, !rev);
			row = row->next;
		}
		map = map->next;
	}
}
