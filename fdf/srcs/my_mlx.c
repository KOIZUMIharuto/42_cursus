/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:46:46 by xxxx              #+#    #+#             */
/*   Updated: 2024/06/10 15:24:27 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static double	**malloc_z_buffer(void);
static int		key_hook(int keycode, t_vars *vars);
static int		window_close(t_vars *vars);

void	mymlx_main(t_map ***map)
{
	t_vars	vars;

	vars.map = map;
	vars.z_buffer = malloc_z_buffer();
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fdf");
	vars.img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img,
			&vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	vars.pre_mouse = create_vector4(WIDTH / 2, HEIGHT / 2, 0, 0);
	if (vars.map && vars.mlx && vars.win
		&& vars.img.img && vars.img.addr && vars.pre_mouse)
	{
		mlx_hook(vars.win, ON_MOUSEMOVE, 0, mouse_move, &vars);
		mlx_hook(vars.win, ON_MOUSEDOWN, 0, mouse_down, &vars);
		mlx_hook(vars.win, ON_MOUSEUP, 0, mouse_up, &vars);
		mlx_key_hook(vars.win, key_hook, &vars);
		mlx_hook(vars.win, ON_DESTROY, 0, window_close, &vars);
		mlx_loop_hook(vars.mlx, draw, &vars);
		mlx_loop(vars.mlx);
	}
	window_close(&vars);
}

static double	**malloc_z_buffer(void)
{
	double	**z_buffer;
	int		x;
	int		y;

	z_buffer = (double **)ft_calloc(HEIGHT, sizeof(double *));
	if (!z_buffer)
		return (NULL);
	y = -1;
	while (++y < HEIGHT)
	{
		z_buffer[y] = (double *)ft_calloc(WIDTH, sizeof(double));
		if (!z_buffer[y])
		{
			while (--y >= 0)
				free (z_buffer[y]);
			free (z_buffer);
			return (NULL);
		}
		x = -1;
		while (++x < WIDTH)
			z_buffer[y][x] = -DBL_MAX;
	}
	return (z_buffer);
}

static int	window_close(t_vars *vars)
{
	int	y;

	free_map3(vars->map, 0);
	y = -1;
	while (++y < HEIGHT)
		free(vars->z_buffer[y]);
	free (vars->z_buffer);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img.img);
	exit(0);
}

static int	key_hook(int keycode, t_vars *vars)
{
	printf("keycode	: %d\n", keycode);
	if (keycode == KEY_ESC)
		window_close(vars);
	return (0);
}
