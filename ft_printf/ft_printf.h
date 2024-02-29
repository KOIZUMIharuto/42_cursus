/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:49:00 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/02/26 14:14:20 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const	char *str, ...);
int		print_arg(char str, va_list *arg, int len);
char	*c_to_str(va_list *arg, char sign);
char	*arg_to_str(va_list *arg);
char	*arg_to_hex(va_list *arg, char sign);
char	*ul_to_hex(unsigned long ul, char *num_list);
char	*ft_uitoa(unsigned int ui);

#endif
