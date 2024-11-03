/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:55:00 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/11/03 14:47:28 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

# define USAGE "Usage: ./philo num_of_philo time_to_die \
time_to_eat time_to_sleep [num_of_times_each_philo_must_eat]"
# define INVALID_ARG "Invalid arg"

typedef struct s_data
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_must_eat;
	pthread_t		*philos;
	pthread_mutex_t	*forks;
}	t_data;


int		ft_atoi_philo(const char *str);
void	error_exit(char *error_msg);


#endif
