/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:56:24 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/29 14:32:23 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	error_exit(t_vars *vars, char *error_message);

int	mouse_move(int x, int y, t_vars *vars)
{
	t_vector	delta;

	if (vars->on_mouse_down)
	{
		delta = (t_vector){vars->pre_mouse.x - x, vars->pre_mouse.y - y, 0};
		if (!vars->is_shift)
		{
			add_vector(&vars->model_center, delta, false);
			trans(vars->map, &delta, true);
		}
		else
		{
			vars->rotate_angle.x = rad(delta.y);
			vars->rotate_angle.y = -rad(delta.x);
			trans(vars->map, &vars->model_center, true);
			rotate(vars->map, &vars->rotate_angle, false);
			trans(vars->map, &vars->model_center, false);
		}
	}
	vars->pre_mouse.x = x;
	vars->pre_mouse.y = y;
	return (0);
}

int	mouse_down(int key, int x, int y, t_vars *vars)
{
	if (key == Button1)
		vars->on_mouse_down = true;
	else if (key == Button4 || key == Button5)
	{
		add_vector(&vars->model_center, (t_vector){x, y, 0}, false);
		mult_vector(&vars->model_center, ZOOM_RATIO, key == Button5);
		add_vector(&vars->model_center, (t_vector){x, y, 0}, true);
		trans(vars->map, &(t_vector){x, y, 0}, true);
		if (!scale(vars->map, ZOOM_RATIO, key == Button5))
			return (error_exit(vars, ZOOM_ERROR));
		trans(vars->map, &(t_vector){x, y, 0}, false);
	}
	return (0);
}

int	mouse_up(int key, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (key == Button1)
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
