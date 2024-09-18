/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:24:26 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/09/18 15:20:02 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static int	print_arg(int fd, char sign, va_list *arg, int len);

int	ft_dprintf(int fd, const char *str, ...)
{
	va_list	arguments;
	int		len;
	int		is_print_success;

	va_start(arguments, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
			is_print_success = print_arg(fd, *(str++ + 1), &arguments, 0);
		else
			is_print_success = write (fd, (char *)str, 1);
		if (is_print_success < 0)
			return (-1);
		len += is_print_success;
		str++;
	}
	va_end(arguments);
	return (len);
}

static int	print_arg(int fd, char sign, va_list *arg, int len)
{
	char	*str_for_write;

	str_for_write = NULL;
	if (sign == 'c' || sign == '%')
	{
		str_for_write = c_to_str(arg, sign);
		len = 1;
	}
	else if (sign == 's')
		str_for_write = arg_to_str(arg);
	else if (sign == 'p' || sign == 'x' || sign == 'X')
		str_for_write = arg_to_hex(arg, sign);
	else if (sign == 'd' || sign == 'i')
		str_for_write = ft_itoa(va_arg(*arg, int));
	else if (sign == 'u')
		str_for_write = ft_uitoa(va_arg(*arg, unsigned int));
	if (!str_for_write)
		return (-1);
	if (!len)
		len = ft_strlen(str_for_write);
	len = write (fd, str_for_write, len);
	free(str_for_write);
	return (len);
}
