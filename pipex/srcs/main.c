/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:49:39 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/09 10:49:44 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int	infile_fd;
	int	outfile_fd;
	int	pipe_fd[2];

	if (argc < 5)
	{
		ft_putendl_fd(USAGE_ERROR, 2);
		return (1);
	}
	infile_fd = open(argv[1], O_RDONLY);
	if (infile_fd == -1)
	{
		perror("open");
		return (1);
	}
	close(infile_fd);
	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q pipex");
}
