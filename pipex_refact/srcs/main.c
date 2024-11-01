/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:49:39 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/10/30 16:36:54 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	main(int argc, char *argv[], char *envp[])
{
	t_vars	vars;

	if (argc < 5)
	{
		ft_putendl_fd(USAGE_ERROR, 2);
		exit(EXIT_FAILURE);
	}
	vars = (t_vars){-1, -1, -1, NULL, NULL, NULL, {-1, -1}, -1};
	vars.outfile_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (vars.outfile_fd == -1)
		print_msgs(strerror(errno), argv[argc - 1]);
	vars.infile_fd = open(argv[1], O_RDONLY);
	if (vars.infile_fd == -1)
		print_msgs(strerror(errno), argv[1]);
	vars.cmds = &argv[2];
	vars.cmds_count = argc - 3;
	vars.envp = envp;
	pipex(&vars);
	return (0);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q pipex");
// }
