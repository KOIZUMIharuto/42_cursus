/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:41:10 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/27 11:49:51 by hkoizumi         ###   ########.fr       */
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

// #include <stdlib.h>
// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	if (argc >= 2)
// 	{
// 		printf("atoi    : %s -> %d\n", argv[1], atoi(argv[1]));
// 		printf("ft_atoi : %s -> %d\n", argv[1], ft_atoi(argv[1]));
// 	}
// 	return (0);
// }
