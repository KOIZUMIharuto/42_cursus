/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:26:52 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/11/11 15:10:43 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	my_atoi(const char *str)
{
	long	result;

	while (str && (('\t' <= *str && *str <= '\r') || *str == ' '))
		str++;
	if (!str || !*str || *str == '-')
		return (-1);
	if (*str == '+')
		str++;
	result = 0;
	while (*str)
	{
		if ((*str < '0' || '9' < *str)
			|| (LONG_MAX - (*str - '0')) / 10 <= result)
			return (-1);
		result = result * 10 + (*(str++) - '0');
	}
	return ((int)result);
}

int	my_error(char *errmsg)
{
	if (errmsg)
		printf("%s\n", errmsg);
	return (1);
}

int	plog(t_philo *philo, long long *log_time, const char *str)
{
	long long	current;

	if (my_mutex_lock(philo->died))
		return (1);
	if (get_time(&current))
		return (1);
	if (log_time)
		*log_time = current;
	if (!*philo->fin)
		if (printf("%lld %d %s\n", current, philo->id, str) < 0)
			return (my_error(EPRINTF));
	if (my_mutex_unlock(philo->died))
		return (1);
	return (0);
}

int	get_time(long long *time)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (my_error(EGETTIMEOFDAY));
	*time = ((long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000);
	return (0);
}
