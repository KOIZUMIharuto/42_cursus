/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:49:27 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/10/10 16:00:20 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	child_process(t_vars *vars, int *pipe_fd, int index);
static void	exec_last_cmd(t_vars *vars, int index);

void	pipex(t_vars *vars)
{
	pid_t	pid;
	int		pipe_fd[2];
	int		index;

	index = 0;
	while (index < vars->cmds_count - 1)
	{
		if (pipe(pipe_fd) == -1)
			error_exit(vars, strerror(errno), "pipe", errno);
		pid = fork();
		if (pid == -1)
			error_exit(vars, strerror(errno), "fork", errno);
		else if (pid == 0)
			child_process(vars, pipe_fd, index);
		close(pipe_fd[1]);
		close(vars->infile_fd);
		vars->infile_fd = pipe_fd[0];
		index++;
	}
	exec_last_cmd(vars, index);
	while (index-- >= 0)
		wait(NULL);
}

static void	child_process(t_vars *vars, int *pipe_fd, int index)
{
	close(pipe_fd[0]);
	dup2(vars->infile_fd, STDIN_FILENO);
	close(vars->infile_fd);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	error_exit(vars, NULL, NULL, exec_cmd(vars->cmds[index], vars->envp));
}

static void	exec_last_cmd(t_vars *vars, int index)
{
	dup2(vars->infile_fd, STDIN_FILENO);
	close(vars->infile_fd);
	dup2(vars->outfile_fd, STDOUT_FILENO);
	close(vars->outfile_fd);
	error_exit(vars, NULL, NULL, exec_cmd(vars->cmds[index], vars->envp));
}