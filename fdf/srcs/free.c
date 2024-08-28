/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:21:33 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/22 15:44:06 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	free_map(t_map *map)
{
	if (map->dots)
	{
		while (--map->y >= 0)
			if (map->dots[map->y])
				free (map->dots[map->y]);
		free(map->dots);
	}
	map->dots = NULL;
}
