/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:34:58 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/10/10 14:54:31 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	digit_counter(int n);
static int	ft_abs(int n);

char	*ft_itoa(int n)
{
	char	*result;
	int		digit_count;
	int		sign;

	digit_count = digit_counter(n);
	result = (char *)malloc ((digit_count + 1) * sizeof(char));
	if (!result)
		return (NULL);
	sign = 1;
	if (n < 0)
		sign = -1;
	result[digit_count] = '\0';
	while (--digit_count >= 0)
	{
		result[digit_count] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	if (sign == -1)
		result[0] = '-';
	return (result);
}

static int	digit_counter(int n)
{
	int	digit_count;

	digit_count = 0;
	if (n <= 0)
		digit_count++;
	while (n <= -1 || 1 <= n)
	{
		digit_count++;
		n /= 10;
	}
	return (digit_count);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
