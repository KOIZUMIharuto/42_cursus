/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:34:31 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/28 14:44:54 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	*free_cmds(char **cmds, int index)
{
	while (cmds[index])
		free(cmds[index++]);
	return (NULL);
}

void	free_vars(t_vars *vars)
{
	if (vars->infile_fd != -1)
		close(vars->infile_fd);
	if (vars->outfile_fd != -1)
		close(vars->outfile_fd);
	if (vars->cmds)
		free_cmds(vars->cmds, 0);
}