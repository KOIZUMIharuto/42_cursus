/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:21:33 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/11 16:12:29 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	*free_map3(t_map ***map, int free_index)
{
	if (map)
	{
		while (map[free_index])
			free_map2(map[free_index++]);
		free (map);
	}
	return (NULL);
}

void	*free_map2(t_map **map)
{
	int	index;

	if (map)
	{
		index = 0;
		while (map[index])
		{
			free_map(map[index++]);
		}
		free (map);
	}
	return (NULL);
}

void	*free_map(t_map *map)
{
	free (map->base);
	free (map->fixed);
	free (map);
	return (NULL);
}
