/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:34:31 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/10/21 16:24:30 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	free_cmds(char **cmds, int index)
{
	while (cmds[index])
		free(cmds[index++]);
}

void	close_fds(t_vars *vars)
{
	if (vars->infile_fd != -1)
		close(vars->infile_fd);
	if (vars->outfile_fd != -1)
		close(vars->outfile_fd);
}
