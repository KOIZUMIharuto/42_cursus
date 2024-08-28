/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:41:28 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/28 14:46:08 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static char	*get_path(char *cmd, char **envp);

int	exec_cmd(char *cmd, char **envp)
{
	char	**cmds;
	char	*path;

	cmds = split_cmd(cmd);
	if (!cmds)
		return (1);
	path = get_path(cmds[0], envp);
	if (!path)
		return (1);
	execve(path, cmds, envp);
	perror("execve"); // エラー出力 "no such file or directory"
	free(path);
	return (1);
}

static char	*get_path(char *cmd, char **envp)
{
	char	*path;
	char	**paths;
	int		i;

	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			paths = ft_split(*envp + 5, ":");
			if (!paths)
				return (NULL);
			i = -1;
			while (paths[++i])
			{
				path = ft_strjoin(ft_strjoin(paths[i], "/"), cmd);
				if (!path)
					return (NULL); // エラー出力
				if (access(path, F_OK) == 0)
				{
					free_cmds(paths, 0);
					return (path);
				}
				free(path);
			}
			free_cmds(paths, 0);
			break ;
		}
		envp++;
	}
	return (NULL); // エラー出力 "command not found"
}
