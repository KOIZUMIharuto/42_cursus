/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:49:27 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/10/29 22:40:34 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	fork_child(t_vars *vars, int index);
static bool	dup_fds(t_vars *vars, int *output_fd);
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
		if (close_wrapper(&vars->pipe_fd[0]) == -1)
			error_exit(vars, strerror(errno), "close", EXIT_FAILURE);
	}
	exec_last_cmd(vars, index);
	if (close_wrapper(&vars->infile_fd) == -1)
		error_exit(vars, strerror(errno), "close", EXIT_FAILURE);
	wait_children(vars);
}

static void	fork_child(t_vars *vars, int index)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error_exit(vars, strerror(errno), "fork", 1);
	else if (pid == 0)
	{
		if (close_wrapper(&vars->pipe_fd[0]) == -1)
			error_exit(vars, strerror(errno), "close", EXIT_FAILURE);
		if (!dup_fds(vars, &vars->pipe_fd[1]))
			error_exit(vars, NULL, NULL, EXIT_FAILURE);
		(void)exec_cmd(vars, vars->cmds[index], vars->envp);
		error_exit(vars, NULL, NULL, EXIT_FAILURE);
	}
	if (close_wrapper(&vars->pipe_fd[1]) == -1)
		error_exit(vars, strerror(errno), "close", EXIT_FAILURE);
}

static void	exec_last_cmd(t_vars *vars, int index)
{
	vars->last_pid = fork();
	if (vars->last_pid == -1)
		error_exit(vars, strerror(errno), "fork", 1);
	else if (vars->last_pid == 0)
	{
		if (!dup_fds(vars, &vars->outfile_fd))
			error_exit(vars, NULL, NULL, EXIT_FAILURE);
		exit(exec_cmd(vars, vars->cmds[index], vars->envp));
	}
	if (close_wrapper(&vars->outfile_fd) == -1)
		error_exit(vars, strerror(errno), "close", EXIT_FAILURE);
}

static bool	dup_fds(t_vars *vars, int *output_fd)
{
	if (vars->infile_fd < 0 || *output_fd < 0)
		return (false);
	if (vars->infile_fd >= 0 && dup2(vars->infile_fd, STDIN_FILENO) == -1)
		error_exit(vars, strerror(errno), "dup2", EXIT_FAILURE);
	if (close_wrapper(&vars->infile_fd) == -1)
		error_exit(vars, strerror(errno), "close", EXIT_FAILURE);
	if (*output_fd >= 0 && dup2(*output_fd, STDOUT_FILENO) == -1)
		error_exit(vars, strerror(errno), "dup2", EXIT_FAILURE);
	if (close_wrapper(output_fd) == -1)
		error_exit(vars, strerror(errno), "close", EXIT_FAILURE);
	return (true);
}

static void	wait_children(t_vars *vars)
{
	int	status;

	if (waitpid(vars->last_pid, &status, 0) == -1)
		error_exit(vars, strerror(errno), "waitpid", EXIT_FAILURE);
	while (wait(NULL) != -1)
		;
	if (errno != ECHILD)
		error_exit(vars, strerror(errno), "wait", EXIT_FAILURE);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	exit(EXIT_FAILURE);
}
