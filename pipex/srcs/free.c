/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:34:31 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/09 14:56:49 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	*free_cmds(char **cmds, int index, void *ret)
{
	while (cmds[index])
		free(cmds[index++]);
	free(cmds);
	return (ret);
}
