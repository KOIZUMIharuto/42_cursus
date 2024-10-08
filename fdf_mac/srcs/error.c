/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:36:52 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/03 14:49:38 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
