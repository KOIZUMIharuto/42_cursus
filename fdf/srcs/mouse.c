/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:56:24 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/14 13:30:20 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	mouse_move(int x, int y, t_vars *vars)
{
	if (vars->pre_mouse->w)
	{
		vars->tran_center->x = WIDTH / 2;
		vars->tran_center->y = HEIGHT / 2;
		if (!trans(vars->map, vars->tran_center, false, true))
			return (1);
		vars->rotate_center->x = rad(vars->pre_mouse->y - y);
		vars->rotate_center->y = -rad(vars->pre_mouse->x - x);
		if (!rotate(vars->map, vars->rotate_center, false, false))
			return (1);
		if (!trans(vars->map, vars->tran_center, false, false))
			return (1);
	}
	vars->pre_mouse->x = x;
	vars->pre_mouse->y = y;
	return (0);
}

int	mouse_down(int key, int x, int y, t_vars *vars)
{
	if (key == LEFT)
		vars->pre_mouse->w = 1;
	else if (key == SCLOLL_UP || key == SCLOLL_DOWN)
	{
		if (!trans(vars->map, create_vector4(x, y, 0, 1), true, true))
			return (1);
		if (!scale(vars->map, 1.1, key == SCLOLL_DOWN))
			return (1);
		if (!trans(vars->map, create_vector4(x, y, 0, 1), true, false))
			return (1);
	}
	return (0);
}

int	mouse_up(int key, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (key == LEFT)
		vars->pre_mouse->w = 0;
	return (0);
}
