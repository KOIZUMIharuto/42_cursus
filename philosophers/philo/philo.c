/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:14:12 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/11/08 00:11:12 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <philo.h>

static int	philo_eat(t_philo *philo);
static int	take_fork(t_philo *philo);
static int	philo_wait(t_philo *philo, long long start, long long time);

void	*do_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!*philo->fin)
	{
		if (philo_eat(philo))
			return (NULL);
		// if (philo_sleep(philo))
		// 	return (NULL);
		// if (philo_think(philo))
		// 	return (NULL);
	}
	return (NULL);
}

static int	philo_eat(t_philo *philo)
{
	if (take_fork(philo) || my_mutex_lock(philo->died))
		return (1);
	philo->last_eat = get_time();
	if (my_mutex_unlock(philo->died) || plog(philo, philo->last_eat, EAT))
		return (1);
	if (philo_wait(philo, philo->last_eat, philo->time_to_eat))
		return (1);
	if (philo->num_of_must_eat >= 0)
	{
		philo->eat_count++;
		if (philo->eat_count == philo->num_of_must_eat)
		{
			if (my_mutex_lock(philo->ate))
				return (1);
			(*philo->ate_philo_count)++;
			if (*philo->ate_philo_count == philo->num_of_philo)
				*philo->fin = true;
			if (my_mutex_unlock(philo->ate))
				return (1);
		}
	}
	if (my_mutex_unlock(philo->forks[0]) || my_mutex_unlock(philo->forks[1]))
		return (1);
	return (0);
}

static int	take_fork(t_philo *philo)
{
	if (philo->id % 2)
	{
		if (my_mutex_lock(philo->forks[0]) || plog(philo, get_time(), FORK))
			return (1);
		if (usleep(100))
			return (my_error(ESLEEP));
		if (my_mutex_lock(philo->forks[1]) || plog(philo, get_time(), FORK))
			return (1);
	}
	else
	{
		if (my_mutex_lock(philo->forks[1]) || plog(philo, get_time(), FORK))
			return (1);
		if (usleep(100))
			return (my_error(ESLEEP));
		if (my_mutex_lock(philo->forks[0]) || plog(philo, get_time(), FORK))
			return (1);
	}
	return (0);
}

static int	philo_wait(t_philo *philo, long long start, long long time)
{
	if (start < 0)
		start = get_time();
	while (start + time >= get_time())
	{
		if (philo->last_eat + philo->time_to_die < get_time())
		{
			if (set_fin(&philo->died->mutex, philo->fin))
				return (1);
			if (plog(philo, get_time(), DIED))
				return (1);
			return (0);
		}
		usleep(100);
	}
	return (0);
}

