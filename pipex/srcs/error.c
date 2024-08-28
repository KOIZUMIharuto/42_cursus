/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 23:09:25 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/23 23:12:35 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	error_exit(t_vars *vars, char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	if (vars)
		free_vars(vars);
	exit(1);
}
