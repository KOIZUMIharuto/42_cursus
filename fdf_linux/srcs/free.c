/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:21:33 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/10 12:36:44 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	*free_map3(t_map ***map, int free_index, char *error_message)
{
	if (map)
	{
		while (map[free_index])
			free_map2(map[free_index++], 0, NULL);
		free (map);
	}
	if (error_message)
		ft_putendl_fd(error_message, 2);
	return (NULL);
}

void	*free_map2(t_map **map, int free_index, char *error_message)
{
	if (map)
	{
		while (map[free_index])
		{
			free_map(map[free_index++], NULL);
		}
		free (map);
	}
	if (error_message)
		ft_putendl_fd(error_message, 2);
	return (NULL);
}

void	*free_map(t_map *map, char *error_message)
{
	free (map->base);
	free (map->fixed);
	free (map);
	if (error_message)
		ft_putendl_fd(error_message, 2);
	return (NULL);
}
