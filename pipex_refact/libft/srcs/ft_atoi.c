/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:41:10 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/10/10 14:54:57 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_atoi(const char *str)
{
	long	result;
	int		sign;

	while (str && (('\t' <= *str && *str <= '\r') || *str == ' '))
		str++;
	sign = 1;
	if (str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = 0;
	while (str && ('0' <= *str && *str <= '9'))
	{
		if (result < INT_MIN / 10 || INT_MAX / 10 < result)
			return (-(sign + 1) / 2);
		result *= 10;
		if (result < INT_MIN + (*str - '0')
			|| INT_MAX - (*str - '0') < result)
			return (-(sign + 1) / 2);
		result += sign * (*(str++) - '0');
	}
	return ((int)result);
}
