/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:55:00 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/11/08 00:10:43 by hkoizumi         ###   ########.fr       */
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
# include <stdbool.h>

# define USAGE "Usage: ./philo [philo] [die] [eat] [sleep] ([must_eat])"
# define EARG "Invalid arg"
# define EMALLOC "Error: malloc: Memory allocation failed"
# define EMUTEX_INIT "Error: pthread_mutex_init: Mutex initialization failed"
# define EMUTEX_LOCK "Error: pthread_mutex_lock: Mutex lock failed"
# define EMUTEX_UNLOCK "Error: pthread_mutex_unlock: Mutex unlock failed"
# define EMUTEX_DESTROY "Error: pthread_mutex_destroy: Mutex destroy failed"
# define ETHREAD_CREATE "Error: pthread_create: Thread creation failed"
# define ETHREAD_JOIN "Error: pthread_join: Thread join failed"
# define ETHREAD_DETACH "Error: pthread_detach: Thread detach failed"
# define EGETTIMEOFDAY "Error: gettimeofday: gettimeofday failed"
# define ESLEEP "Error: usleep: usleep failed"

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"

typedef struct s_my_mutex
{
	bool			is_init;
	pthread_mutex_t	mutex;
}	t_my_mutex;

typedef struct s_philo
{
	int			id;
	int			num_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_of_must_eat;
	pthread_t	thread;
	t_my_mutex	*forks[2];
	long long	last_eat;
	int			eat_count;
	t_my_mutex	*ate;
	int			*ate_philo_count;
	t_my_mutex	*died;
	bool		*fin;
}	t_philo;

typedef struct s_data
{
	int			num_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_of_must_eat;
	t_philo		*philos;
	t_my_mutex	*forks;
	t_my_mutex	ate;
	int			ate_philo_count;
	t_my_mutex	died;
	bool		fin;
	pthread_t	watcher;
}	t_data;


int			init_data(t_data *data, int argc, char **argv);
int			my_atoi(const char *str);

int			my_mutex_init(t_my_mutex *my_mutex);
int			my_mutex_destroy(t_my_mutex *my_mutex);
int			my_mutex_lock(t_my_mutex *my_mutex);
int			my_mutex_unlock(t_my_mutex *my_mutex);

int			create_thread(t_data *data);
void		*do_philo(void *arg);

int			set_fin(pthread_mutex_t *died_mutex, bool *fin);
int			plog(t_philo *philo, long long time, const char *str);
long long	get_time(void);

int			my_error(char *error_msg);
int			free_data(t_data *data, char *error_msg, int ret);


#endif
