/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:58:39 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/11/11 15:17:18 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	check_fin(t_my_mutex *died_mutex, bool *fin, bool *is_fin)
{
	if (my_mutex_lock(died_mutex))
		return (my_error(EMUTEX_LOCK));
	if (*fin)
		*is_fin = true;
	else
		*is_fin = false;
	if (my_mutex_unlock(died_mutex))
		return (my_error(EMUTEX_UNLOCK));
	return (0);
}

int	set_fin(t_my_mutex *died_mutex, bool *fin, int died_philo)
{
	long long	current;

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
