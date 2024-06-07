/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:12:14 by xxxx              #+#    #+#             */
/*   Updated: 2024/06/07 17:34:12 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fdf.h"

int	mouse_move(int x, int y, t_vars *vars)
{
	if (vars->pre_mouse->w)
	{
		if (!trans(vars->map, create_vector4(WIDTH / 2, HEIGHT / 2, 0, 1), true, true))
			return (1);
		if (!rotate(vars->map, create_vector4(rad(vars->pre_mouse->y - y), -rad(vars->pre_mouse->x - x), 0, 1), true, false))
			return (1);
		if (!trans(vars->map, create_vector4(WIDTH / 2, HEIGHT / 2, 0, 1), true, false))
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
		if (!scale(vars->map, create_vector4(1.1, 1.1, 1.1, 1), true, key == SCLOLL_DOWN))
			return (1);
		if (!trans(vars->map, create_vector4(x, y, 0, 1), true, false))
			return (1);
	}
	return (0);
}

int mouse_up(int key, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (key == LEFT)
		vars->pre_mouse->w = 0;
	return (0);
}