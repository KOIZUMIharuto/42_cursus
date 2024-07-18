/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:56:24 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/24 13:57:27 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	error_exit(t_vars *vars, char *error_message);

int	mouse_move(int x, int y, t_vars *vars)
{
	if (vars->pre_mouse->w)
	{
		if (!vars->is_shift)
		{
			vars->tran_center->x = vars->pre_mouse->x - x;
			vars->tran_center->y = vars->pre_mouse->y - y;
			if (!trans(vars->map, vars->tran_center, false, true))
				return (error_exit(vars, TRANSLATE_ERROR_MESSAGE));
		}
		else
		{
			*(vars->tran_center) = (t_vector){WIDTH / 2, HEIGHT / 2, 0, 0};
			vars->rotate_angle->x = rad(vars->pre_mouse->y - y);
			vars->rotate_angle->y = -rad(vars->pre_mouse->x - x);
			if (!trans(vars->map, vars->tran_center, false, true)
				|| !rotate(vars->map, vars->rotate_angle, false, false)
				|| !trans(vars->map, vars->tran_center, false, false))
				return (error_exit(vars, ROTATE_ERROR_MESSAGE));
		}
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
		if (!trans(vars->map, create_vector4(x, y, 0, 1), true, true)
			|| !scale(vars->map, 1.1, key == SCLOLL_DOWN)
			|| !trans(vars->map, create_vector4(x, y, 0, 1), true, false))
			return (error_exit(vars, ZOOM_ERROR_MESSAGE));
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

static int	error_exit(t_vars *vars, char *error_message)
{
	perror(error_message);
	window_close(vars);
	return (1);
}
