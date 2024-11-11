/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:09:35 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/11/11 12:22:22 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	detach_all(t_data *data);

void	free_data(t_data *data, bool do_unlock)
{
	int	i;

	detach_all(data);
	if (do_unlock)
		unlock_all(data);
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
}

void	unlock_all(t_data *data)
{
	int	i;

	if (!data->forks)
		return ;
	i = -1;
	while (++i < data->num_of_philo)
		if (data->forks[i].is_locked)
			my_mutex_unlock(&data->forks[i]);
	if (data->ate.is_locked)
		my_mutex_unlock(&data->ate);
	if (data->died.is_locked)
		my_mutex_unlock(&data->died);
}

static void	detach_all(t_data *data)
{
	int	i;

	i = -1;
	if (data->philos)
		while (++i < data->num_of_philo)
			if (!data->philos[i].thread.is_done)
				pthread_detach(data->philos[i].thread.thread);
	if (!data->observer.is_done)
		pthread_detach(data->observer.thread);
}
