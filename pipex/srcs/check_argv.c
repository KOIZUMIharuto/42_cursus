/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:53:35 by xxxx              #+#    #+#             */
/*   Updated: 2024/04/12 00:10:49 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void free_cmd(char ***cmd);

char	***check_argv(int argc, char *argv[])
{
	char	***cmd;

	if (argc != 5)
	{
		ft_putendl_fd("Error: Wrong number of arguments", 2);
		return (NULL);
	}
	if (!argv[1] || !argv[2] || !argv[3] || !argv[4])
	{
		ft_putendl_fd("Error: NULL argument", 2);
		return (NULL);
	}
	cmd = (char ***)malloc(sizeof(char **) * 3);
	if (!cmd)
	{
		ft_putendl_fd(strerror(errno), 2);
		return (NULL);
	}
	cmd[0] = ft_split(argv[2], ' ');
	cmd[1] = ft_split(argv[3], ' ');
	cmd[2] = NULL;
	if (!cmd[0] || !cmd[1])
	{
		ft_putendl_fd(strerror(errno), 2);
		free_cmd(cmd);
		return (NULL);
	}
	return (cmd);
}

static void free_cmd(char ***cmd)
{
	int i;
	int j;

	i = 0;
	while (cmd[i])
	{
		j = 0;
		while (cmd[i][j])
		{
			free(cmd[i][j]);
			j++;
		}
		free(cmd[i]);
		i++;
	}
	free(cmd);
}