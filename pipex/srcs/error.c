/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 23:09:25 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/09/24 15:00:38 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	print_msgs(char *msg, char *cause)
{
	if (msg)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(msg, 2);
	}
	if (cause)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(cause, 2);
	}
	ft_putchar_fd('\n', 2);
}

void	error_exit(t_vars *vars, char *msg, char *cause)
{
	if (msg)
		print_msgs(msg, cause);
	if (vars)
		close_fds(vars);
	exit(1);
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
