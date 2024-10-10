/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:41:28 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/10/10 15:00:40 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static bool	get_path(char **path, char *cmd, char **envp);
static bool	find_path(char **path, char *paths, char *cmd);

int	exec_cmd(char *cmd, char **envp)
{
	char	**cmds;
	char	*path;

	cmds = split_cmd(cmd);
	if (!cmds)
		return (1);
	if (!get_path(&path, cmds[0], envp))
		return (1);
	execve(path, cmds, envp);
	print_msgs(strerror(errno), path);
	free(path);
	return (errno);
}

static bool	get_path(char **path, char *cmd, char **envp)
{
	if (ft_strchr(cmd, '/'))
	{
		*path = ft_strdup(cmd);
		return (*path != NULL);
	}
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			break ;
		envp++;
	}
	if (!*envp)
		return (error_return_bool("command not found", cmd));
	return (find_path(path, *envp + 5, cmd));
}

static bool	find_path(char **path, char *envp, char *cmd)
{
	char	*tmp;
	char	**paths;
	int		i;

	paths = ft_split(envp, ":");
	if (!paths)
		return (error_return_bool(strerror(errno), "malloc"));
	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		*path = ft_strjoin(tmp, cmd);
		free (tmp);
		if (!*path)
			return (error_return_bool(strerror(errno), "malloc"));
		if (access(*path, F_OK) == 0)
		{
			free_cmds(paths, 0);
			return (true);
		}
		free(*path);
	}
	free_cmds(paths, 0);
	return (error_return_bool("command not found", cmd));
}
