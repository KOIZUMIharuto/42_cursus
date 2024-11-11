/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:34:48 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/11/11 12:28:18 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	fail_create_thread(t_data *data, int i);

int	create_thread(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philo)
		data->philos[i].thread.is_done = true;
	data->observer.is_done = true;
	i = -1;
	while (++i < data->num_of_philo)
	{
		data->philos[i].thread.is_done = false;
		if (pthread_create(&data->philos[i].thread.thread,
				NULL, &do_philo, &data->philos[i]))
			return (fail_create_thread(data, i));
	}
	data->observer.is_done = false;
	if (pthread_create(&data->observer.thread, NULL, &do_observer, data))
		return (fail_create_thread(data, i));
	return (0);
}

static int	fail_create_thread(t_data *data, int i)
{
	while (--i >= 0)
	{
		data->philos[i].thread.is_done = true;
		if (pthread_detach(data->philos[i].thread.thread))
			return (my_error(ETHREAD_DETACH));
	}
	if (!data->observer.is_done && pthread_detach(data->observer.thread))
		return (my_error(ETHREAD_DETACH));
	if (set_fin(&data->died, &data->fin, -1))
		return (1);
	return (my_error(ETHREAD_CREATE));
}
