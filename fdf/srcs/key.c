/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:43:21 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/22 11:25:05 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	key_pressed(int key_code, t_vars *vars)
{
	if (key_code == KEY_ESC)
		win_off(vars);
	else if (key_code == KEY_SFT_L)
		vars->is_shift = true;
	else if (key_code == KEY_R)
	{
		*(vars->model_ctr) = (t_vector){WIDTH / 2, HEIGHT / 2, 0};
		copy_vector(vars->map, true);
	}
	return (0);
}

int	key_released(int key_code, t_vars *vars)
{
	if (key_code == KEY_SFT_L)
		vars->is_shift = false;
	return (0);
}
