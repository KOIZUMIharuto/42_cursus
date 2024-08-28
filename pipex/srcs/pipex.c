/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:49:27 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/28 14:44:38 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

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
        if (pid == 0)
        {
            close(pipe_fd[0]);
            dup2(vars->infile_fd, STDIN_FILENO);
			close(vars->infile_fd);
            dup2(pipe_fd[1], STDOUT_FILENO);
            close(pipe_fd[1]);
            exec_cmd(vars->cmds[index], vars->envp);
            error_exit(vars, strerror(errno));
        }
		if (waitpid(pid, NULL, 0) == -1)
			error_exit(vars, strerror(errno));
        close(pipe_fd[1]);
        close(vars->infile_fd);
        vars->infile_fd = pipe_fd[0];
		index++;
    }
    dup2(vars->infile_fd, STDIN_FILENO);
    dup2(vars->outfile_fd, STDOUT_FILENO);
    exec_cmd(vars->cmds[index], vars->envp);
    error_exit(vars, strerror(errno));
}
