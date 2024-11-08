/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:31:32 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/11/08 14:22:30 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	my_error(char *errmsg)
{
	// bool	lock;

	// lock = false;
	// if (!check_locked || !died->is_locked)
	// 	if (pthread_mutex_lock(&died->mutex) == 0)
	// 		lock = true;
	if (errmsg)
		printf("%s\n", errmsg);
	// *fin = true;
	// if ((!check_locked || !died->is_locked) && lock)
	// 	pthread_mutex_unlock(&died->mutex);
	return (1);
}
