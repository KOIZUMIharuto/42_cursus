/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:56:24 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/19 10:59:29 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	error_exit(t_vars *vars, char *error_message);

int	mouse_move(int x, int y, t_vars *vars)
{
	t_vector	delta;

	if (vars->on_mouse_down)
	{
		delta = (t_vector){vars->pre_mouse->x - x, vars->pre_mouse->y - y, 0};
		if (!vars->is_shift)
		{
			add_vector(vars->model_center, delta, false);
			if (!trans(vars->map, &delta, false, true))
				return (error_exit(vars, TRANSLATE_ERROR));
		}
		else
		{
			vars->rotate_angle->x = rad(delta.y);
			vars->rotate_angle->y = -rad(delta.x);
			if (!trans(vars->map, vars->model_center, false, true)
				|| !rotate(vars->map, vars->rotate_angle, false, false)
				|| !trans(vars->map, vars->model_center, false, false))
				return (error_exit(vars, ROTATE_ERROR));
		}
	}
	vars->pre_mouse->x = x;
	vars->pre_mouse->y = y;
	return (0);
}

int	mouse_down(int key, int x, int y, t_vars *vars)
{
	if (key == LEFT)
		vars->on_mouse_down = true;
	else if (key == SCLOLL_UP || key == SCLOLL_DOWN)
	{
		add_vector(vars->model_center, (t_vector){x, y, 0}, false);
		mult_vector(vars->model_center, ZOOM_RATIO, key == SCLOLL_DOWN);
		add_vector(vars->model_center, (t_vector){x, y, 0}, true);
		if (!trans(vars->map, create_vector(x, y, 0), true, true)
			|| !scale(vars->map, ZOOM_RATIO, key == SCLOLL_DOWN)
			|| !trans(vars->map, create_vector(x, y, 0), true, false))
			return (error_exit(vars, ZOOM_ERROR));
	}
	return (0);
}

int	mouse_up(int key, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (key == LEFT)
		vars->on_mouse_down = false;
	return (0);
}

static int	error_exit(t_vars *vars, char *error_message)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(error_message, 2);
	vars->exit_status = 1;
	win_off(vars);
	return (1);
}
