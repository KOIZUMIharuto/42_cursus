/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:21:33 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/05/30 15:48:38 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	*free_data(t_data ***data)
{
	int	index_1;
	int	index_2;

	if (data)
	{
		index_1 = 0;
		while (data[index_1])
		{
			index_2 = 0;
			while (data[index_1][index_2])
				free (data[index_1][index_2++]);
			index_1++;
			free (data[index_1]);
		}
		free (data);
	}
	return (NULL);
}
