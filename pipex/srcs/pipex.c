/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:49:27 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/09/11 12:45:49 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	child_process(t_vars *vars, int *pipe_fd, int index);

void	pipex(t_vars *vars)
{
    pid_t	pid;
    int		pipe_fd[2];
	int		index;

	index = 0;
    while (vars->cmds_count-- > 1)
    {
        if (pipe(pipe_fd) == -1)
            error_exit(vars, strerror(errno));
        pid = fork();
        if (pid == -1)
            error_exit(vars, strerror(errno));
        else if (pid == 0)
			child_process(vars, pipe_fd, index);
        close(pipe_fd[1]);
        close(vars->infile_fd);
		if (waitpid(pid, NULL, 0) == -1)
			error_exit(vars, strerror(errno));
        vars->infile_fd = pipe_fd[0];
		index++;
    }
    dup2(vars->infile_fd, STDIN_FILENO);
    dup2(vars->outfile_fd, STDOUT_FILENO);
    exec_cmd(vars->cmds[index], vars->envp);
    error_exit(vars, strerror(errno));
}

static void	child_process(t_vars *vars, int *pipe_fd, int index)
{
	close(pipe_fd[0]);
	dup2(vars->infile_fd, STDIN_FILENO);
	close(vars->infile_fd);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	exec_cmd(vars->cmds[index], vars->envp);
	error_exit(vars, strerror(errno));
}