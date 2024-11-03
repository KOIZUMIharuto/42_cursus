/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:50:25 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/11/03 11:05:57 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>

# include "../libft/includes/libft.h"

# define USAGE_ERROR "Usage: ./pipex file1 cmd1 cmd2 file2"
# define USAGE_ERROR_BONUS "Usage: ./pipex file1 cmd1 cmd2 ... cmdn file2"
# define SEQUENCE_ERROR "escape sequence error"
# define NO_COMMAND_ERROR "no command entry"
# define NO_SUCH_ERROR "No such file or directory"
# define NOT_FOUND_ERROR "command not found"
# define EXIT_NOENT 127
# define EXIT_EACCES 126

typedef struct s_esc
{
	bool	double_q;
	bool	single_q;
	bool	bacl_s;
}	t_esc;

typedef struct s_vars
{
	int			infile_fd;
	int			outfile_fd;
	int			cmds_count;
	char		**cmds;
	char		**envp;
	char		**cmd_opt;
	int			pipe_fd[2];
	pid_t		last_pid;
}	t_vars;

char	**split_cmd(char *cmd);

void	pipex(t_vars *vars);
int		exec_cmd(t_vars *vars, char *cmds);

void	print_msgs(char *msg, char *cause);
void	error_exit(t_vars *vars, char *msg, char *cause, int exit_status);
bool	error_return_bool(char *msg, char *cause);
void	*error_return_null(char *msg, char *cause);
void	free_vars(t_vars *vars);
void	free_cmds(char **cmds, int index);
int		close_wrapper(int *fd);

#endif
