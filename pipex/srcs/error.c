/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 23:09:25 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/09/18 15:33:46 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	error_exit(t_vars *vars, char *msg, char *cause)
{
	if (msg)
		ft_dprintf(2, "pipex: %s", msg);
	if (cause)
		ft_dprintf(2, ": %s\n", cause);
	else
		ft_putchar_fd(2, '\n');
	if (vars)
		close_fds(vars);
	exit(1);
}

bool	error_return_bool(char *msg, char *cause)
{
	if (msg)
		ft_dprintf(2, "pipex: %s", msg);
	if (cause)
		ft_dprintf(2, ": %s\n", cause);
	else
		ft_putchar_fd(2, '\n');
	return (false);
}

void	*error_return_null(char *msg, char *cause)
{
	if (msg)
		ft_dprintf(2, "pipex: %s", msg);
	if (cause)
		ft_dprintf(2, ": %s\n", cause);
	else
		ft_putchar_fd(2, '\n');
	return (NULL);
}
