/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:53:23 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/11/11 12:12:38 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	lonely_philo(t_data *data);
static int	wait_philos(t_data *data);
static int	wait_thread(t_data *data, t_my_thread *target);

int	main(int argc, char **argv)
{
	t_data	data;

	if (init_data(&data, argc, argv))
	{
		free_data(&data, false);
		return (1);
	}
	if (data.num_of_philo == 1)
		return (lonely_philo(&data));
	if (create_thread(&data) || wait_philos(&data)
		|| wait_thread(&data, &data.observer))
	{
		free_data(&data, true);
		return (1);
	}
	free_data(&data, false);
	return (0);
}

static int	lonely_philo(t_data *data)
{
	if (plog(&data->philos[0], &data->philos[0].last_eat, FORK)
		|| philo_wait(&data->philos[0],
			data->philos[0].last_eat, data->time_to_die)
		|| set_fin(&data->died, &data->fin, data->philos[0].id))
	{
		free_data(data, true);
		return (1);
	}
	free_data(data, true);
	return (0);
}

static int	wait_philos(t_data *data)
{
	int		i;

	i = -1;
	while (++i < data->num_of_philo)
		if (wait_thread(data, &data->philos[i].thread))
			return (1);
	return (0);
}

static int	wait_thread(t_data *data, t_my_thread *target)
{
	bool	*is_success;
	bool	tmp;

	if (target->is_done)
		return (0);
	target->is_done = true;
	if (pthread_join(target->thread, (void **)&is_success))
		return (my_error(ETHREAD_JOIN));
	if (!is_success)
		return (my_error(EMALLOC));
	tmp = *is_success;
	free(is_success);
	if (!tmp)
	{
		unlock_all(data);
		if (set_fin(&data->died, &data->fin, -1))
			return (1);
	}
	return (0);
}
