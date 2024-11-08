/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:53:23 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/11/08 15:46:57 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	wait_philos(t_data *data);
static int	wait_observer(t_data *data);

int	main(int argc, char **argv)
{
	t_data	data;

	if(init_data(&data, argc, argv)|| create_thread(&data))
	{
		free_data(&data, true);
		return (1);
	}
	if (wait_philos(&data) || wait_observer(&data))
	{
		free_data(&data, true);
		return (1);
	}
	free_data(&data, false);
	return (0);
}

static int	wait_philos(t_data *data)
{
	int		i;
	bool	*is_success;
	bool	tmp;

	i = -1;
	while (++i < data->num_of_philo)
	{
		if (pthread_join(data->philos[i].thread, (void **)&is_success))
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
	}
	return (0);
}

static int	wait_observer(t_data *data)
{
	if (pthread_join(data->observer, NULL))
		return (my_error(ETHREAD_JOIN));
	return (0);
}
