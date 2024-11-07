/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:07:53 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/11/07 16:49:11 by hkoizumi         ###   ########.fr       */
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
			|| (LONG_MAX - (*str - '0')) / 10 < result)
			return (-1);
		result = result * 10 + (*(str++) - '0');
	}
	return ((int)result);
}
