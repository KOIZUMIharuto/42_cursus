/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:53:35 by xxxx              #+#    #+#             */
/*   Updated: 2024/05/17 13:52:11 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void free_cmd(char ***cmd);

char	***check_argv(int argc, char *argv[])
{
	char	***cmd;
	int		index;

	if (argc < 5)
	{
		ft_putendl_fd(ARG_NUM_ERROR, 2);
		return (NULL);
	}
	cmd = (char ***)malloc(sizeof(char **) * (argc - 2));
	if (!cmd)
	{
		ft_putendl_fd(strerror(errno), 2);
		return (NULL);
	}
	index = 0;
	while (index < argc - 3)
	{
		cmd[index] = (char **)malloc(sizeof(char *) * 3);
		if (!cmd[index])
		{
			ft_putendl_fd(strerror(errno), 2);
			free_cmd(cmd);
			return (NULL);
		}
		cmd[index] = ft_split(argv[index + 2], "\n\t\v\f\r ");
		index++;
	}
	cmd[index] = NULL;
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

// int main(int argc, char **argv)
// {
// 	char	***cmd;
// 	int		index_1;
// 	int		index_2;

// 	for (int i = 0; i < argc; i++)
// 	{
// 		ft_putendl_fd(argv[i], 1);
// 	}
// 	ft_putchar_fd('\n', 1);
// 	cmd = check_argv(argc, argv);
// 	if (!cmd)
// 		return (1);
// 	index_1 = 0;
// 	while (cmd[index_1])
// 	{
// 		index_2 = 0;
// 		while (cmd[index_1][index_2])
// 		{
// 			ft_putendl_fd(cmd[index_1][index_2], 1);
// 			free(cmd[index_1][index_2]);
// 			index_2++;
// 		}
// 		ft_putchar_fd('\n', 1);
// 		free(cmd[index_1]);
// 		index_1++;
// 	}
// 	free(cmd);
// 	return (0);
// }
	