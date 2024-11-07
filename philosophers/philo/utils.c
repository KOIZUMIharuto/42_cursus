/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:26:52 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/11/08 00:11:36 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	set_fin(pthread_mutex_t *died_mutex, bool *fin)
{
	if (pthread_mutex_lock(died_mutex))
		return (my_error(EMUTEX_LOCK));
	*fin = true;
	if (pthread_mutex_unlock(died_mutex))
		return (my_error(EMUTEX_UNLOCK));
	return (0);
}

int	plog(t_philo *philo, long long time, const char *str)
{
	if (pthread_mutex_lock(&philo->died->mutex))
		return (my_error(EMUTEX_LOCK));
	if (!*philo->fin)
		printf("%lld %d %s\n", time, philo->id, str);
	if (pthread_mutex_unlock(&philo->died->mutex))
		return (my_error(EMUTEX_UNLOCK));
	return (0);
}

long long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
	{
		printf("%s\n", EGETTIMEOFDAY);
		return (-1);
	}
	return ((long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000);
}
