/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:50:25 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/09 14:56:56 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>

# include "../libft/includes/libft.h"

# define USAGE_ERROR "Usage: ./pipex file1 cmd1 cmd2 file2"

typedef struct s_esc
{
	bool	double_q;
	bool	single_q;
	bool	bacl_s;
}	t_esc;

char	**split_cmd(char *cmd);
void	*free_cmds(char **cmds, int index, void *ret);

#endif
