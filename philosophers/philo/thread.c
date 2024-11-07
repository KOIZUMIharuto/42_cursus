/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:34:48 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/11/07 22:14:25 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	create_thread(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philo)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &do_philo, &data->philos[i]))
		{
			while (--i >= 0)
				if (pthread_detach(data->philos[i].thread))
					return (my_error(ETHREAD_DETACH));
			if (set_fin(&data->died.mutex, &data->fin))
				return (1);
			return (my_error(ETHREAD_CREATE));
		}
	}
	return (0);
}
