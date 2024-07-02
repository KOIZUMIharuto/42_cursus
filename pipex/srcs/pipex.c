/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:49:27 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/25 13:32:15 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		index;
	int		index2;
	char	**commands;

	(void)envp;
	index = 0;
	while (index < argc)
	{
		ft_putendl_fd(argv[index], 1);
		index++;
	}
	index = 0;
	while (index < argc)
	{
		commands = split_command(argv[index]);
		if (!commands)
		{
			ft_putendl_fd("split_command failed", 2);
			return (1);
		}
		index2 = 0;
		ft_putchar_fd('\n', 1);
		while (commands[index2])
		{
			ft_putendl_fd(commands[index2], 1);
			free(commands[index2]);
			index2++;
		}
		free(commands);
		index++;
	}
	return (0);
}
// 
// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q pipex");
// }
