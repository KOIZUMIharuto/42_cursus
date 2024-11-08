/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:34:48 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/11/08 16:55:35 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	create_thread(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philo)
	{
		if (pthread_create(&data->philos[i].thread,
				NULL, &do_philo, &data->philos[i]) == 0)
			continue ;
		while (--i >= 0)
			if (pthread_detach(data->philos[i].thread))
				return (my_error(ETHREAD_DETACH));
		if (set_fin(&data->died, &data->fin, -1))
			return (1);
		return (my_error(ETHREAD_CREATE));
	}
	if (pthread_create(&data->observer, NULL, &do_observer, data) == 0)
		return (0);
	i = -1;
	while (++i < data->num_of_philo)
		if (pthread_detach(data->philos[i].thread))
			return (my_error(ETHREAD_DETACH));
	if (set_fin(&data->died, &data->fin, -1))
		return (1);
	return (my_error(ETHREAD_CREATE));
}
