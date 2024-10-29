/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:34:31 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/10/29 22:38:56 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	free_vars(t_vars *vars)
{
	if (close_wrapper(&vars->infile_fd) == -1)
		error_exit(NULL, strerror(errno), "close", EXIT_FAILURE);
	if (close_wrapper(&vars->outfile_fd) == -1)
		error_exit(NULL, strerror(errno), "close", EXIT_FAILURE);
	if (close_wrapper(&vars->pipe_fd[0]) == -1)
		error_exit(NULL, strerror(errno), "close", EXIT_FAILURE);
	if (close_wrapper(&vars->pipe_fd[1]) == -1)
		error_exit(NULL, strerror(errno), "close", EXIT_FAILURE);
}

void	free_cmds(char **cmds, int index)
{
	while (cmds[index])
		free(cmds[index++]);
	free (cmds);
}

int	close_wrapper(int *fd)
{
	if (*fd < 0)
		return (0);
	if (close(*fd) == -1)
		return (-1);
	*fd = -1;
	return (0);
}
