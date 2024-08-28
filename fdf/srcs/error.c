/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:36:52 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/27 11:31:51 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	send_msg(char *message, int fd)
{
	if (fd == 1)
		ft_putstr_fd("Warning: ", fd);
	else if (fd == 2)
		ft_putstr_fd("Error: ", fd);
	ft_putendl_fd(message, fd);
}

void	*return_msg_null(char *message, int fd)
{
	if (message)
		send_msg(message, fd);
	return (NULL);
}

void	*return_msg_bool(char *message, int fd)
{
	if (message)
		send_msg(message, fd);
	return (false);
}
