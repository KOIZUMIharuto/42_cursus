/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:23:34 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/05 12:28:59 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	x_y_counter(t_data ***data, int *x, int *y)
{
	int		x_tmp;

	*y = 0;
	while (data[*y])
	{
		*x = 0;
		while (data[*y][*x])
			(*x)++;
		if (*y != 0 && *x != x_tmp)
			return (false);
		x_tmp = *x;
		(*y)++;
	}
	return (true);
}
