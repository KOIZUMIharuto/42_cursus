/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:49:39 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/28 14:49:19 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	main(int argc, char *argv[], char *envp[])
{
	t_vars	vars;

	if (argc < 5)
		error_exit(NULL, USAGE_ERROR);
	vars = (t_vars){-1, -1, -1, NULL, NULL};
	vars.infile_fd = open(argv[1], O_RDONLY);
	if (vars.infile_fd == -1)
		error_exit(NULL, strerror(errno));
	vars.outfile_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (vars.outfile_fd == -1)
		error_exit(&vars, strerror(errno));
	vars.cmds =  &argv[2];
	if (!vars.cmds)
		error_exit(&vars, strerror(errno));
	vars.cmds_count = argc - 3;
	vars.envp = envp;
	pipex(&vars);
	free_vars(&vars);
	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q pipex");
}
