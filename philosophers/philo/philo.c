/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:14:12 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/11/14 15:55:26 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static bool	philo_routine(t_philo *philo);
static int	philo_eat(t_philo *philo);
static int	take_fork(t_philo *philo);

int	philo_wait(t_philo *philo, long long start, long long time)
{
	long long	current;
	bool		is_fin;

	if (start < 0 && get_time(&start))
		return (1);
	while (1)
	{
		if (get_time(&current))
			return (1);
		if (check_fin(philo->died, philo->fin, &is_fin))
			return (1);
		if (start + time < current || is_fin)
			break ;
		if (philo->last_eat + philo->time_to_die < current)
		{
			if (set_fin(philo->died, philo->fin, philo->id))
				return (1);
			return (0);
		}
		usleep(100);
	}
	return (0);
}

void	*do_philo(void *arg)
{
	t_philo		*philo;
	bool		*is_success;

	philo = (t_philo *)arg;
	is_success = (bool *)malloc(sizeof(bool));
	if (!is_success)
	{
		set_fin(philo->died, philo->fin, -1);
		return (NULL);
	}
	*is_success = false;
	if (get_time(&philo->last_eat) || plog(philo, NULL, THINK))
		return (is_success);
	*is_success = philo_routine(philo);
	return (is_success);
}

static bool	philo_routine(t_philo *philo)
{
	long long	sleep_start;
	bool		is_fin;

	is_fin = false;
	while (1)
	{
		if (check_fin(philo->died, philo->fin, &is_fin))
			return (false);
		if (is_fin)
			break ;
		if (philo_eat(philo))
			return (false);
		if (plog(philo, &sleep_start, SLEEP)
			|| philo_wait(philo, sleep_start, philo->time_to_sleep))
			return (false);
		if (plog(philo, NULL, THINK))
			return (false);
	}
	return (true);
}

static int	philo_eat(t_philo *philo)
{
	if (take_fork(philo))
		return (1);
	if (plog(philo, &philo->last_eat, EAT)
		|| philo_wait(philo, philo->last_eat, philo->time_to_eat))
		return (1);
	if (philo->num_of_must_eat >= 0)
	{
		if (++philo->eat_count == philo->num_of_must_eat)
		{
			if (my_mutex_lock(philo->ate))
				return (1);
			if ((++(*philo->ate_philo_count) == philo->num_of_philo
					&& set_fin(philo->died, philo->fin, -1))
				|| my_mutex_unlock(philo->ate))
				return (1);
		}
	}
	if (my_mutex_unlock(philo->forks[0]) || my_mutex_unlock(philo->forks[1]))
		return (1);
	return (0);
}

static int	take_fork(t_philo *philo)
{
	if (philo->id % 2 == 1)
	{
		if (my_mutex_lock(philo->forks[0]) || plog(philo, NULL, FORK))
			return (1);
		if (usleep(300))
			return (my_error(ESLEEP));
		if (my_mutex_lock(philo->forks[1]) || plog(philo, NULL, FORK))
			return (1);
	}
	else
	{
		if (usleep(300))
			return (my_error(ESLEEP));
		if (my_mutex_lock(philo->forks[1]) || plog(philo, NULL, FORK))
			return (1);
		if (my_mutex_lock(philo->forks[0]) || plog(philo, NULL, FORK))
			return (1);
	}
	return (0);
}
