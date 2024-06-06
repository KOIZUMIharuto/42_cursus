/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:21:33 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/06 17:10:42 by xxxx             ###   ########.fr       */
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
			free_data(data[index++]);
		}
		free (data);
	}
	return (NULL);
}

void	*free_data(t_data *data)
{
	free (data->base);
	free (data->fixed);
	free (data);
	return (NULL);
}