/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:26:24 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/11/14 15:55:52 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	check_philos(t_data *data);

void	*do_observer(void *arg)
{
	t_data		*data;
	bool		*is_success;
	bool		is_fin;

	data = (t_data *)arg;
	is_success = (bool *)malloc(sizeof(bool));
	if (!is_success)
	{
		set_fin(&data->died, &data->fin, -1);
		return (NULL);
	}
	*is_success = false;
	while (1)
	{
		if (check_fin(&data->died, &data->fin, &is_fin))
			return (is_success);
		if (is_fin)
			break ;
		if (check_philos(data))
			return (is_success);
		usleep(50);
	}
	*is_success = true;
	return (is_success);
}

static int	check_philos(t_data *data)
{
	int			i;
	long long	current;

	i = -1;
	while (++i < data->num_of_philo)
	{
		if (my_mutex_lock(&data->died) || get_time(&current))
			return (1);
		if (data->philos[i].last_eat != -1
			&& data->philos[i].last_eat + data->time_to_die <= current)
			if (set_fin(NULL, &data->fin, data->philos[i].id))
				return (1);
		if (my_mutex_unlock(&data->died))
			return (1);
	}
	return (0);
}
