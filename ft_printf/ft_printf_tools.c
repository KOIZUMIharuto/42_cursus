/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:03:59 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/02/16 16:36:41 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uitoa(unsigned int ui)
{
	char	*a_1;
	char	*a_2;
	char	*a;

	a_1 = ft_itoa((int)(ui / 10));
	if (!a_1)
		return (NULL);
	a_2 = ft_itoa((int)(ui % 10));
	if (!a_2)
	{
		free (a_1);
		return (NULL);
	}
	if (ui < 10)
	{
		free(a_1);
		return (a_2);
	}
	a = ft_strjoin(a_1, a_2);
	free(a_1);
	free(a_2);
	if (!a)
		return (NULL);
	return (a);
}

char	*ul_to_hex(unsigned long ul, char *num_list)
{
	unsigned long	ul_tmp;
	int				digit_count;
	char			*hex;

	ul_tmp = ul;
	digit_count = 1;
	while (ul_tmp >= 16)
	{
		ul_tmp /= 16;
		digit_count++;
	}
	hex = (char *)malloc ((digit_count + 1) * sizeof(char));
	if (!hex)
		return (NULL);
	hex[digit_count] = '\0';
	while (--digit_count >= 0)
	{
		hex[digit_count] = num_list[ul % 16];
		ul /= 16;
	}
	return (hex);
}

char	*arg_to_hex(va_list *arg, char sign)
{
	unsigned long	ul;
	char			*hex;
	char			*address;

	if (sign == 'p')
		ul = (unsigned long)va_arg(*arg, void *);
	if (sign == 'x' || sign == 'X')
		ul = (unsigned long)((unsigned int)va_arg(*arg, int));
	if (sign == 'p' || sign == 'x')
		hex = ul_to_hex(ul, "0123456789abcdef");
	if (sign == 'X')
		hex = ul_to_hex(ul, "0123456789ABCDEF");
	if (!hex)
		return (NULL);
	if (sign == 'x' || sign == 'X')
		return (hex);
	address = ft_strjoin("0x", hex);
	if (hex)
		free(hex);
	if (!address)
		return (NULL);
	return (address);
}

char	*arg_to_str(va_list *arg)
{
	char	*input_str;
	char	*output_str;

	input_str = va_arg(*arg, char *);
	output_str = NULL;
	if (!input_str)
		output_str = ft_strdup("(null)");
	else
		output_str = ft_strdup(input_str);
	return (output_str);
}

void	print_arg(char str, va_list *arg, size_t *len)
{
	char	*str_for_write;

	str_for_write = NULL;
	if (str == 'c' || str == '%')
	{
		if (str == 'c')
			ft_putchar_fd(va_arg(*arg, int), 1);
		else
			ft_putchar_fd('%', 1);
	}
	if (str == 's')
		str_for_write = arg_to_str(arg);
	if (str == 'p' || str == 'x' || str == 'X')
		str_for_write = arg_to_hex(arg, str);
	if (str == 'd' || str == 'i')
		str_for_write = ft_itoa(va_arg(*arg, int));
	if (str == 'u')
		str_for_write = ft_uitoa(va_arg(*arg, unsigned int));
	if (!str_for_write)
		return ;
	*len += ft_strlen(str_for_write) - 1;
	write (1, str_for_write, ft_strlen(str_for_write));
	free(str_for_write);
}
