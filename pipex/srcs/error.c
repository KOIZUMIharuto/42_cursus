/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 23:09:25 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/10/25 13:57:55 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	print_msgs(char *msg, char *cause)
{
	if (ft_strncmp(NO_CMD_ERROR, msg, ft_strlen(msg)) != 0)
		ft_putstr_fd("pipex: ", 2);
	if (cause)
	{
		ft_putstr_fd(cause, 2);
		ft_putstr_fd(": ", 2);
	}
	if (msg)
		ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
}

void	error_exit(t_vars *vars, char *msg, char *cause, int exit_status)
{
	if (msg)
		print_msgs(msg, cause);
	if (vars)
		close_fds(vars);
	exit(exit_status);
}

bool	error_return_bool(char *msg, char *cause)
{
	if (msg)
		print_msgs(msg, cause);
	return (false);
}

void	*error_return_null(char *msg, char *cause)
{
	if (msg)
		print_msgs(msg, cause);
	return (NULL);
}
