/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:50:25 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/03 16:40:22 by hkoizumi         ###   ########.fr       */
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

typedef struct s_esc
{
	bool	double_q;
	bool	single_q;
	bool	bacl_s;
}	t_esc;

char	**split_command(char *command);
void	*free_commands(char **commands, int index);

#endif
