/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:22:35 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/11/11 12:41:11 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	my_mutex_init(t_my_mutex *my_mutex)
{
	if (!my_mutex->is_init && pthread_mutex_init(&my_mutex->mutex, NULL))
		return (my_error(EMUTEX_INIT));
	my_mutex->is_init = true;
	return (0);
}

int	my_mutex_destroy(t_my_mutex *my_mutex)
{
	if (my_mutex->is_init && pthread_mutex_destroy(&my_mutex->mutex))
		return (my_error(EMUTEX_DESTROY));
	my_mutex->is_init = false;
	return (0);
}

int	my_mutex_lock(t_my_mutex *my_mutex)
{
	if (pthread_mutex_lock(&my_mutex->mutex))
		return (my_error(EMUTEX_LOCK));
	my_mutex->is_locked = true;
	return (0);
}

int	my_mutex_unlock(t_my_mutex *my_mutex)
{
	my_mutex->is_locked = false;
	if (pthread_mutex_unlock(&my_mutex->mutex))
	{
		my_mutex->is_locked = true;
		return (my_error(EMUTEX_UNLOCK));
	}
	return (0);
}
