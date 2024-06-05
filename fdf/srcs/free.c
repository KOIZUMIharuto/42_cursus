/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:21:33 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/05 16:39:51 by hkoizumi         ###   ########.fr       */
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
			free_vector(data[index++]);
		}
		free (data);
	}
	return (NULL);
}

void	*free_vector(t_data *data)
{

	free (data->origin);
	free (data->fixed);
	free (data);

}