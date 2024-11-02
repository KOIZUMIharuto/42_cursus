/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 23:09:25 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/11/03 00:46:53 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	error_exit(t_vars *vars, char *msg, char *cause, int exit_status)
{
	if (msg)
		print_msgs(msg, cause);
	if (vars)
		free_vars(vars);
	exit(exit_status);
}

void	print_msgs(char *msg, char *cause)
{
	if (ft_strncmp(NOT_FOUND_ERROR, msg, ft_strlen(msg)) != 0)
		ft_putstr_fd("pipex: ", STDERR_FILENO);
	if (cause)
	{
		ft_putstr_fd(cause, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (msg)
		ft_putstr_fd(msg, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
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
