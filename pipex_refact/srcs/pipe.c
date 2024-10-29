/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:49:27 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/10/29 17:16:37 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	fork_child(t_vars *vars, int index);
static void	dup_fds(t_vars *vars);
static void	exec_last_cmd(t_vars *vars, int index);
static void	wait_children(t_vars *t_vars);

void	pipex(t_vars *vars)
{
	int		index;

	index = 0;
	while (index < vars->cmds_count - 1)
	{
		if (pipe(vars->pipe_fd) == -1)
			error_exit(vars, strerror(errno), "pipe", 1);
		fork_child(vars, index++);
		if (close_wrapper(&vars->infile_fd) == -1)
			error_exit(vars, strerror(errno), "close", EXIT_FAILURE);
		vars->infile_fd = dup(vars->pipe_fd[0]);
		if (vars->infile_fd == -1)
			error_exit(vars, strerror(errno), "dup", EXIT_FAILURE);
	}
	exec_last_cmd(vars, index);
	wait_children(vars);
}

static void	fork_child(t_vars *vars, int index)
{
	t_process	*process;

	process = (t_process *)malloc(sizeof(t_process));
	if (!process)
		error_exit(vars, strerror(errno), "malloc", 1);
	process->prev = vars->processes;
	vars->processes = process;
	dup_fds(vars);
	process->pid = fork();
	if (process->pid == -1)
		error_exit(vars, strerror(errno), "fork", 1);
	else if (process->pid == 0)
	{
		close_wrapper(&vars->pipe_fd[0]);
		(void)exec_cmd(vars, vars->cmds[index], vars->envp);
		error_exit(vars, NULL, NULL, EXIT_FAILURE);
	}
}

static void	dup_fds(t_vars *vars)
{
	if (vars->infile_fd >= 0 && dup2(vars->infile_fd, STDIN_FILENO) == -1)
		error_exit(vars, strerror(errno), "dup2", EXIT_FAILURE);
	if (close_wrapper(&vars->infile_fd) == -1)
		error_exit(vars, strerror(errno), "close", EXIT_FAILURE);
	if (vars->pipe_fd[1] >= 0 && dup2(vars->pipe_fd[1], STDOUT_FILENO) == -1)
		error_exit(vars, strerror(errno), "dup2", EXIT_FAILURE);
	if (close_wrapper(&vars->pipe_fd[1]) == -1)
		error_exit(vars, strerror(errno), "close", EXIT_FAILURE);
	vars->processes->read_fd = STDIN_FILENO;
	vars->processes->write_fd = STDOUT_FILENO;
}

static void	exec_last_cmd(t_vars *vars, int index)
{
	t_process	*process;

	process = (t_process *)malloc(sizeof(t_process));
	if (!process)
		error_exit(vars, strerror(errno), "malloc", 1);
	process->prev = vars->processes;
	vars->processes = process;
	if (vars->infile_fd >= 0 && dup2(vars->infile_fd, STDIN_FILENO) == -1)
		error_exit(vars, strerror(errno), "dup2", EXIT_FAILURE);
	if (close_wrapper(&vars->infile_fd) == -1)
		error_exit(vars, strerror(errno), "close", EXIT_FAILURE);
	if (vars->outfile_fd >= 0 && dup2(vars->outfile_fd, STDOUT_FILENO) == -1)
		error_exit(vars, strerror(errno), "dup2", EXIT_FAILURE);
	if (close_wrapper(&vars->outfile_fd) == -1)
		error_exit(vars, strerror(errno), "close", EXIT_FAILURE);
	process->read_fd = STDIN_FILENO;
	process->write_fd = STDOUT_FILENO;
	process->pid = fork();
	if (process->pid == -1)
		error_exit(vars, strerror(errno), "fork", 1);
	else if (process->pid == 0)
		exit(exec_cmd(vars, vars->cmds[index], vars->envp));
}

static void	wait_children(t_vars *vars)
{
	int			status;
	int			result;
	t_process	*process;

	waitpid(vars->processes->pid, &status, 0);
	process = vars->processes->prev;
	while (process)
	{
		result = waitpid(process->pid, NULL, WNOHANG);
		if (result == 0)
		{
			if (close_wrapper(&process->read_fd) == -1)
				error_exit(vars, strerror(errno), "close", EXIT_FAILURE);
			waitpid(process->pid, NULL, 0);
		}
		else if (result == -1)
			error_exit(vars, strerror(errno), "waitpid", EXIT_FAILURE);
		process = process->prev;
	}
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	exit(EXIT_FAILURE);
}
