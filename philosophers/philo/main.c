/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:53:23 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/11/03 15:43:23 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	init_data(t_data *data, int argc, char **argv);

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || 6 < argc)
	{
		printf("%s\n", USAGE);
		exit (0);
	}
	init_data(&data, argc, argv);
	return (0);
}

static void	init_data(t_data *data, int argc, char **argv)
{
	data->num_of_philo = ft_atoi_philo(argv[1]);
	data->time_to_die = ft_atoi_philo(argv[2]);
	data->time_to_eat = ft_atoi_philo(argv[3]);
	data->time_to_sleep = ft_atoi_philo(argv[4]);
	if (argc == 6)
		data->num_of_must_eat = ft_atoi_philo(argv[5]);
	else
		data->num_of_must_eat = -1;
	if (data->num_of_philo == -1 || data->time_to_die == -1
		|| data->time_to_eat == -1 || data->time_to_sleep == -1
		|| (argc == 6 && data->num_of_must_eat == -1))
		error_exit(INVALID_ARG);
	data->philos = (pthread_t *)malloc(data->num_of_philo * sizeof(pthread_t));
	if (!data->philos)
		error_exit("Error: malloc");
	data->forks = (pthread_mutex_t *)malloc(
			data->num_of_philo * sizeof(pthread_mutex_t));
	if (!data->forks)
	{
		
	}
}
