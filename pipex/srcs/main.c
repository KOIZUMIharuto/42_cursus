/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:49:39 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/09/18 15:38:38 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	main(int argc, char *argv[], char *envp[])
{
	t_vars	vars;

	if (argc < 5)
		error_exit(NULL, USAGE_ERROR, NULL);
	vars = (t_vars){-1, -1, -1, NULL, NULL};
	vars.infile_fd = open(argv[1], O_RDONLY);
	if (vars.infile_fd == -1)
		error_exit(NULL, strerror(errno), "open");
	vars.outfile_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (vars.outfile_fd == -1)
		error_exit(&vars, strerror(errno), "open");
	vars.cmds = &argv[2];
	vars.cmds_count = argc - 3;
	vars.envp = envp;
	pipex(&vars);
	close_fds(&vars);
	return (0);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q pipex");
// }
