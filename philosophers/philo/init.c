/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:55:53 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/11/08 16:43:29 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	check_args(int argc, t_data *data);
static int 	init_philos(t_data *data);
static int	init_forks(t_data *data);

int	init_data(t_data *data, int argc, char **argv)
{
	data->philos = NULL;
	data->forks = NULL;
	data->ate.is_init = false;
	data->ate.is_locked = false;
	data->ate_philo_count = 0;
	data->died.is_init = false;
	data->died.is_locked = false;
	data->fin = false;
	if (argc != 5 && argc != 6)
		return (my_error(USAGE));
	data->num_of_philo = my_atoi(argv[1]);
	data->time_to_die = my_atoi(argv[2]);
	data->time_to_eat = my_atoi(argv[3]);
	data->time_to_sleep = my_atoi(argv[4]);
	data->num_of_must_eat = my_atoi(argv[5]);
	if (check_args(argc, data) || init_philos(data) || init_forks(data))
		return (1);
	return (0);
}

static int	check_args(int argc, t_data *data)
{
	if (data->num_of_philo <= 0 || 200 < data->num_of_philo)
		return (my_error(EARG));
	if (data->time_to_die <= 0)
		return (my_error(EARG));
	if (data->time_to_eat <= 0)
		return (my_error(EARG));
	if (data->time_to_sleep <= 0)
		return (my_error(EARG));
	if (argc == 6 && data->num_of_must_eat <= 0)
		return (my_error(EARG));
	return (0);
}

static int init_philos(t_data *data)
{
	t_philo	philo;
	int		i;

	data->philos = (t_philo *)malloc(data->num_of_philo * sizeof(t_philo));
	if (!data->philos)
		return (my_error(EMALLOC));
	philo.num_of_philo = data->num_of_philo;
	philo.time_to_die = data->time_to_die;
	philo.time_to_eat = data->time_to_eat;
	philo.time_to_sleep = data->time_to_sleep;
	philo.num_of_must_eat = data->num_of_must_eat;
	memset(philo.forks, 0, sizeof(philo.forks));
	philo.last_eat = -1;
	philo.eat_count = 0;
	philo.ate = &data->ate;
	philo.ate_philo_count = &data->ate_philo_count;
	philo.died = &data->died;
	philo.fin = &data->fin;
	i = -1;
	while (++i < data->num_of_philo)
	{
		philo.id = i + 1;
		data->philos[i] = philo;
	}
	return (0);
}

static int	init_forks(t_data *data)
{
	int	i;

	data->forks = (t_my_mutex *)malloc(data->num_of_philo * sizeof(t_my_mutex));
	if (!data->forks)
		return (my_error(EMALLOC));
	i = -1;
	while (++i < data->num_of_philo)
	{
		data->forks[i].is_init = false;
		data->forks[i].is_locked = false;
		data->philos[i].forks[0] = &data->forks[i];
		data->philos[i].forks[1] = &data->forks[(i + 1) % data->num_of_philo];
	}
	i = -1;
	while (++i < data->num_of_philo)
		if (my_mutex_init(&(data->forks[i])))
			return (my_error(EMUTEX_INIT));
	if (my_mutex_init(&data->ate) || my_mutex_init(&data->died))
		return (my_error(EMUTEX_INIT));
	return (0);
}
