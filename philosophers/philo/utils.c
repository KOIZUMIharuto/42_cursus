/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:26:52 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/11/08 14:43:08 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	set_fin(t_my_mutex *died_mutex, bool *fin, int died_philo)
{
	long long current;

	if (died_mutex && my_mutex_lock(died_mutex))
		return (my_error(EMUTEX_LOCK));
	if (died_philo != -1 && !*fin)
	{
		*fin = true;
		if (get_time(&current))
			return (1);
		if (printf("%lld %d %s\n", current, died_philo, DIED) < 0)
			return (my_error(EPRINTF));
	}
	*fin = true;
	if (died_mutex && my_mutex_unlock(died_mutex))
		return (my_error(EMUTEX_UNLOCK));
	return (0);
}

int	plog(t_philo *philo, long long *log_time, const char *str)
{
	long long current;

	if (pthread_mutex_lock(&philo->died->mutex))
		return (my_error(EMUTEX_LOCK));
	if (get_time(&current))
		return (1);
	if (log_time)
		*log_time = current;
	if (!*philo->fin)
		if (printf("%lld %d %s\n", current, philo->id, str) < 0)
			return (my_error(EPRINTF));
	if (pthread_mutex_unlock(&philo->died->mutex))
		return (my_error(EMUTEX_UNLOCK));
	return (0);
}

int	get_time(long long *time)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return my_error(EGETTIMEOFDAY);
	*time = ((long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000);
	return (0);
}
