/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:24:26 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/02/16 16:36:29 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const	char *str, ...)
{
	va_list	arguments;
	size_t	arg_count;
	size_t	len;

	va_start(arguments, str);
	arg_count = 0;
	len = 0;
	while (*str)
	{
		if (*str == '%')
			print_arg(*(str++ + 1), &arguments, &len);
		else
			write (1, str, 1);
		len++;
		str++;
	}
	va_end(arguments);
	return (len);
}
