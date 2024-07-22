/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:41:28 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/18 13:02:16 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*get_path(char *cmd, char **envp);

int	exec_cmd(char **cmds, char **envp)
{
	char	*path;

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
			paths = ft_split(*envp + 5, ':');
			if (!paths)
				return (NULL);
			i = -1;
			while (paths[++i])
			{
				path = ft_strjoin(ft_strjoin(paths[i], "/"), cmd);
				if (!path)
					return (NULL); // エラー出力
				if (access(path, F_OK) == 0)
					return ((char *)free_cmds(paths, 0, NULL));
				free(path);
			}
			free_cmds(paths, 0, NULL);
			break ;
		}
		envp++;
	}
	return (NULL); // エラー出力 "command not found"
}
