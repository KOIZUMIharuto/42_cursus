/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:36:52 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/19 15:32:43 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <fdf.h>

void	*return_error_null(char *error_message)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(error_message, 2);
	return (NULL);
}

void	*return_error_bool(char *error_message)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(error_message, 2);
	return (false);
}
