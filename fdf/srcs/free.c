/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:21:33 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/05 14:38:54 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	*free_data3(t_data ***data, int free_index)
{
	if (data)
	{
		while (data[free_index])
			free_data2(data[free_index++]);
		free (data);
	}
	return (NULL);
}

void	*free_data2(t_data **data)
{
	int	index;

	if (data)
	{
		index = 0;
		while (data[index])
		{
			free (data[index]->origin);
			free (data[index]->fixed);
			free (data[index++]);
		}
		free (data);
	}
	return (NULL);
}
