/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:41:28 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/10/31 11:23:24 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	get_path(t_vars *vars, char **path);
static void	find_path(t_vars *vars, char **path, char *paths);
static int	get_status(int my_errno);

int	exec_cmd(t_vars *vars, char *cmd)
{
	char	**cmd_opt;
	char	*path;
	int		exit_status;

	cmd_opt = split_cmd(cmd);
	if (!cmd_opt)
		return (EXIT_FAILURE);
	vars->cmd_opt = cmd_opt;
	if (!cmd_opt[0])
		error_exit(vars, NO_COMMAND_ERROR, NULL, EXIT_FAILURE);
	get_path(vars, &path);
	execve(path, cmd_opt, vars->envp);
	exit_status = get_status(errno);
	print_msgs(strerror(errno), path);
	free(path);
	return (exit_status);
}

static void	get_path(t_vars *vars, char **path)
{
	int	index;

	if (ft_strchr(vars->cmd_opt[0], '/'))
	{
		*path = ft_strdup(vars->cmd_opt[0]);
		if (*path == NULL)
			error_exit(vars, strerror(errno), "malloc", EXIT_FAILURE);
		return ;
	}
	index = 0;
	while (vars->envp[index])
	{
		if (ft_strncmp(vars->envp[index], "PATH=", 5) == 0)
			break ;
		index++;
	}
	if (!vars->envp[index])
		error_exit(vars, NO_SUCH_ERROR, vars->cmd_opt[0], EXIT_NOENT);
	find_path(vars, path, vars->envp[index] + 5);
}

static void	find_path(t_vars *vars, char **path, char *envp)
{
	char	*tmp;
	char	**paths;
	int		i;

	paths = ft_split(envp, ":");
	if (!paths)
		error_exit(vars, strerror(errno), "malloc", EXIT_FAILURE);
	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		*path = ft_strjoin(tmp, vars->cmd_opt[0]);
		free (tmp);
		if (!*path || access(*path, F_OK) == 0)
		{
			free_cmds(paths, 0);
			if (!*path)
				error_exit(vars, strerror(errno), "malloc", EXIT_FAILURE);
			return ;
		}
		free(*path);
	}
	free_cmds(paths, 0);
	error_exit(vars, NOT_FOUND_ERROR, vars->cmd_opt[0], EXIT_NOENT);
}

static int	get_status(int my_errno)
{
	if (my_errno == ENOENT)
		return (EXIT_NOENT);
	else if (my_errno == EACCES)
		return (EXIT_EACCES);
	else
		return (EXIT_FAILURE);
}
