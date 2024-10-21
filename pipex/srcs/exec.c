/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:41:28 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/10/21 15:22:08 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	get_path(t_vars *vars, char **path, char *cmd, char **envp);
static void	find_path(t_vars *vars, char **path, char *paths, char *cmd);
static int	get_status(int my_errno);

int	exec_cmd(t_vars *vars, char *cmd, char **envp)
{
	char	**cmds;
	char	*path;
	int		exit_status;

	cmds = split_cmd(cmd);
	if (!cmds)
		return (1);
	get_path(vars, &path, cmds[0], envp);
	execve(path, cmds, envp);
	exit_status = get_status(errno);
	print_msgs(strerror(errno), path);
	free_cmds(cmds, 0);
	free(path);
	return (exit_status);
}

static void	get_path(t_vars *vars, char **path, char *cmd, char **envp)
{
	if (ft_strchr(cmd, '/'))
	{
		*path = ft_strdup(cmd);
		if (*path != NULL)
			error_exit(vars, strerror(errno), "malloc", 1);
		return ;
	}
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			break ;
		envp++;
	}
	if (!*envp)
		error_exit(vars, "No such file or directory", cmd, 127);
	find_path(vars, path, *envp + 5, cmd);
}

static void	find_path(t_vars *vars, char **path, char *envp, char *cmd)
{
	char	*tmp;
	char	**paths;
	int		i;

	paths = ft_split(envp, ":");
	if (!paths)
		error_exit(vars, strerror(errno), "malloc", 1);
	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		*path = ft_strjoin(tmp, cmd);
		free (tmp);
		if (!*path)
			error_exit(vars, strerror(errno), "malloc", 1);
		if (access(*path, F_OK) == 0)
		{
			free_cmds(paths, 0);
			return ;
		}
		free(*path);
	}
	free_cmds(paths, 0);
	error_exit(vars, "command not found", cmd, 127);
}

static int	get_status(int my_errno)
{
	if (my_errno == ENOENT)
		return (127);
	else if (my_errno == EACCES)
		return (126);
	else
		return (1);
}
