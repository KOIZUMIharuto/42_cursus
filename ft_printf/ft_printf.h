/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:49:00 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/02/16 16:36:28 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const	char *str, ...);
void	print_arg(char str, va_list *arguments, size_t *len);
char	*arg_to_str(va_list *arg);
char	*arg_to_hex(va_list *arg, char sign);
char	*ul_to_hex(unsigned long ul, char *num_list);
char	*ft_uitoa(unsigned int ui);

#endif
