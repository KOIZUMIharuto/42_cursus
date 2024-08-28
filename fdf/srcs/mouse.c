/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:56:24 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/22 12:44:27 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	mouse_move(int x, int y, t_vars *vars)
{
	t_vector	delta;

	if (vars->on_mouse_down)
	{
		delta = (t_vector){vars->pre_mouse->x - x, vars->pre_mouse->y - y, 0};
		if (!vars->is_shift && trans(vars->map, &delta, true, TRANSLATE_CANCEL))
			add_vector(vars->model_ctr, delta, false);
		else
		{
			*vars->rotate_angle = (t_vector){rad(delta.y), -rad(delta.x), 0};
			if (trans(vars->map, vars->model_ctr, true, NULL))
			{
				rotate(vars->map, vars->rotate_angle, false);
				if (!trans(vars->map, vars->model_ctr, false, ROTATE_CANCEL))
				{
					rotate(vars->map, vars->rotate_angle, true);
					trans(vars->map, vars->model_ctr, false, NULL);
				}
			}
		}
	}
	*vars->pre_mouse = (t_vector){x, y, 0};
	return (0);
}

int	mouse_down(int key, int x, int y, t_vars *vars)
{
	t_vector	vector;

	if (key == Button1)
		vars->on_mouse_down = true;
	else if (key == Button4 || key == Button5)
	{
		vector = (t_vector){x, y, 0};
		if (trans(vars->map, &vector, true, NULL))
		{
			add_vector(vars->model_ctr, vector, false);
			if (scale(vars->map, ZOOM_RATIO, key == Button5))
				mult_vector(vars->model_ctr, ZOOM_RATIO, key == Button5);
			if (!trans(vars->map, &vector, false, ZOOM_CANCEL))
			{
				scale(vars->map, ZOOM_RATIO, !(key == Button5));
				mult_vector(vars->model_ctr, ZOOM_RATIO, !(key == Button5));
				trans(vars->map, &vector, false, NULL);
			}
			add_vector(vars->model_ctr, vector, true);
		}
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
