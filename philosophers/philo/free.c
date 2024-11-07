/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:09:35 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/11/07 16:20:12 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	free_data(t_data *data, char *error_msg, int ret)
{
	int	i;

	if (data->philos)
		free(data->philos);
	data->philos = NULL;
	if (data->forks)
	{
		i = -1;
		while (++i < data->num_of_philo)
			my_mutex_destroy(&data->forks[i]);
		free(data->forks);
		data->forks = NULL;
	}
	my_mutex_destroy(&data->ate);
	my_mutex_destroy(&data->died);
	if (error_msg)
		return (my_error(error_msg));
	return (ret);
}