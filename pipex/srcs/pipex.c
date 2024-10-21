/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:49:27 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/10/21 14:33:25 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	child_process(t_vars *vars, int *pipe_fd, int index);
static int	exec_last_cmd(t_vars *vars, int index);
static void	wait_children(t_vars *vars, int index, int last_pid);

void	pipex(t_vars *vars)
{
	pid_t	pid;
	int		pipe_fd[2];
	int		index;

	index = 0;
	while (index < vars->cmds_count - 1)
	{
		if (pipe(pipe_fd) == -1)
			error_exit(vars, strerror(errno), "pipe", 1);
		pid = fork();
		if (pid == -1)
			error_exit(vars, strerror(errno), "fork", 1);
		else if (pid == 0)
			child_process(vars, pipe_fd, index);
		close(pipe_fd[1]);
		close(vars->infile_fd);
		vars->infile_fd = pipe_fd[0];
		index++;
	}
	pid = exec_last_cmd(vars, index);
	wait_children(vars, index, pid);
}

static void	child_process(t_vars *vars, int *pipe_fd, int index)
{
	if (pipe_fd[0] > 0)
		close(pipe_fd[0]);
	if (vars->infile_fd > 0)
	{
		dup2(vars->infile_fd, STDIN_FILENO);
		close(vars->infile_fd);
	}
	if (pipe_fd[1] > 0)
	{
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
	}
	if (vars->infile_fd > 0 && pipe_fd[1] > 0)
		exec_cmd(vars, vars->cmds[index], vars->envp);
	error_exit(vars, NULL, NULL, 1);
}

static int	exec_last_cmd(t_vars *vars, int index)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		error_exit(vars, strerror(errno), "fork", 1);
	else if (pid == 0)
	{
		if (vars->infile_fd > 0)
		{
			dup2(vars->infile_fd, STDIN_FILENO);
			close(vars->infile_fd);
		}
		if (vars->outfile_fd > 0)
		{
			dup2(vars->outfile_fd, STDOUT_FILENO);
			close(vars->outfile_fd);
		}
		if (vars->infile_fd > 0 && vars->outfile_fd > 0)
			exit(exec_cmd(vars, vars->cmds[index], vars->envp));
		else
			exit(1);
	}
	return (pid);
}

static void	wait_children(t_vars *vars, int index, int last_pid)
{
	int	status;

	while (index-- >= 1)
	{
		if (wait(NULL) == -1)
			print_msgs(strerror(errno), "wait");
	}
	if (waitpid(last_pid, &status, 0) == -1)
		error_exit(vars, strerror(errno), "waitpid", 1);
	close_fds(vars);
	if (WIFEXITED(status))
		exit (WEXITSTATUS(status));
	else
		exit (1);
}
