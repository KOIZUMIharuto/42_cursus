/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:21:33 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/19 13:16:37 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_map(t_map *map, char *error_message)
{
	if (map->dots)
	{
		while (--map->y >= 0)
			if (map->dots[map->y])
				free (map->dots[map->y]);
		free(map->dots);
	}
	map->dots = NULL;
	if (error_message)
		ft_putendl_fd(error_message, 2);
}
