/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:31:32 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/11/03 13:43:02 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	error_exit(char *error_msg)
{
	int	len;

	if (error_msg)
	{
		len = 0;
		while (error_msg[len])
			len++;
		if (len != 0)
			write(2, error_msg, len);
		write(2, "\n", 1);		
	}
	exit (1);
}
