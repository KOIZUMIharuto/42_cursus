/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:56:41 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/29 16:42:02 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		init_vars(t_vars *vars, t_list *map);
static double	**malloc_z_buffer(void);

void	my_mlx_main(t_list *map)
{
	t_vars	vars;

	init_vars(&vars, map);
	if (vars.map && vars.img.addr && vars.z_buf
		&& vars.mlx && vars.win && vars.img.img)
	{
		mlx_hook(vars.win, ON_MOUSEMOVE, 0, mouse_move, &vars);
		mlx_hook(vars.win, ON_MOUSEDOWN, 0, mouse_down, &vars);
		mlx_hook(vars.win, ON_MOUSEUP, 0, mouse_up, &vars);
		mlx_hook(vars.win, ON_KEY_PRESSED, 0, key_pressed, &vars);
		mlx_hook(vars.win, ON_KEY_RELEASED, 0, key_released, &vars);
		mlx_hook(vars.win, ON_DESTROY, 0, win_off, &vars);
		mlx_loop_hook(vars.mlx, draw, &vars);
		mlx_loop(vars.mlx);
	}
	perror("Error");
	vars.exit_status = 1;
	win_off(&vars);
}

static void	init_vars(t_vars *vars, t_list *map)
{
	vars->map = map;
	vars->z_buf = malloc_z_buffer();
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "fdf");
	vars->img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	vars->on_mouse_down = false;
	vars->is_shift = false;
	vars->pre_mouse = (t_vector){WIDTH / 2, HEIGHT / 2, 0};
	vars->rotate_angle = (t_vector){0, 0, 0};
	vars->model_center = (t_vector){WIDTH / 2, HEIGHT / 2, 0};
	vars->exit_status = 0;
}

static double	**malloc_z_buffer(void)
{
	double	**z_buf;
	int		x;
	int		y;

	z_buf = (double **)ft_calloc(HEIGHT, sizeof(double *));
	if (!z_buf)
		return (NULL);
	y = -1;
	while (++y < HEIGHT)
	{
		z_buf[y] = (double *)ft_calloc(WIDTH, sizeof(double));
		if (!z_buf[y])
		{
			while (--y >= 0)
				free (z_buf[y]);
			free (z_buf);
			return (NULL);
		}
		x = -1;
		while (++x < WIDTH)
			z_buf[y][x] = -DBL_MAX;
	}
	return (z_buf);
}

int	win_off(t_vars *vars)
{
	int	y;

	ft_lstclear(&vars->map, &free_map);
	y = -1;
	if (vars->z_buf)
	{
		while (++y < HEIGHT)
			free(vars->z_buf[y]);
		free (vars->z_buf);
	}
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img.img);
	exit(vars->exit_status);
}
