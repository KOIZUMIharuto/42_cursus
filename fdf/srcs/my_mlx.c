/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:46:46 by xxxx              #+#    #+#             */
/*   Updated: 2024/06/07 17:26:38 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fdf.h"

static int			draw_point(t_vars *vars);
static void			draw_pixel(t_vars *vars, int x, int y, unsigned int color);
// static void 		draw_line(t_vars *vars, t_map *start, t_map *end);
// static unsigned int interpolate_color(unsigned int color1, unsigned int color2, float t);
static void			my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color);
static int			key_hook(int keycode, t_vars *vars);
static int			window_close(t_vars *vars);

void	mymlx_main(t_map ***map)
{
	t_vars	vars;

	vars.map = map;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fdf");
	vars.img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img,
		&vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	vars.pre_mouse = create_vector4(WIDTH / 2, HEIGHT / 2, 0, 0);
	// mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_hook(vars.win, ON_MOUSEMOVE, 0, mouse_move, &vars);
	mlx_hook(vars.win, ON_MOUSEDOWN, 0, mouse_down, &vars);
	mlx_hook(vars.win, ON_MOUSEUP, 0, mouse_up, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, ON_DESTROY, 0, window_close, &vars);
	// draw_point(&vars);
	mlx_loop_hook(vars.mlx, draw_point, &vars);
	mlx_loop(vars.mlx);
}

static int	window_close(t_vars *vars)
{
	free_map3(vars->map, 0);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img.img);
	exit(0);
}

static int	draw_point(t_vars *vars)
{
	int	x;
	int	y;

	ft_memset(vars->img.addr, 0, HEIGHT * vars->img.line_length);
	x = 0;
	while (vars->map[x])
	{
		y = 0;
		while (vars->map[x][y])
		{
			draw_pixel(vars, vars->map[x][y]->fixed->x, vars->map[x][y]->fixed->y, vars->map[x][y]->color);
			// if (vars->map[x][y + 1])
			// 	draw_line(vars, vars->map[x][y], vars->map[x][y + 1]);
			// if (vars->map[x + 1] && vars->map[x + 1][y])
			// 	draw_line(vars, vars->map[x][y], vars->map[x + 1][y]);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}


static void	draw_pixel(t_vars *vars, int x, int y, unsigned int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	my_mlx_pixel_put(&vars->img, x, y, color);
}

static void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	key_hook(int keycode, t_vars *vars)
{
	printf("keycode	: %d\n", keycode);
	if (keycode == KEY_ESC)
		window_close(vars);
	return (0);
}
