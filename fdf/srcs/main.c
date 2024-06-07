/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:00:34 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/07 16:51:53 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static bool	init_isometric_projection(t_map ***map, t_vector4 *win_center);
static bool	init_scale(t_map ***map);
static int	return_error_int(t_map ***map, char *error_message);
// static void	data_printer(t_map ***map);

int	main(int argc, char **argv)
{
	t_map		***map;
	t_vector4	*win_center;

	if (argc < 2)
		return (return_error_int(NULL, USAGE_ERROR_MESSAGE));
	map = get_map(argv[1]);
	if (!map)
		return (1);
	win_center = create_vector4(WIDTH / 2, HEIGHT / 2, 0, 1);
	if (!init_isometric_projection(map, win_center))
		return (1);
	mymlx_main(map);
	free_map3(map, 0);
	return (0);
}

static bool	init_isometric_projection(t_map ***map, t_vector4 *win_center)
{
	t_vector4	*map_center;
	t_vector4	*isometic_vector;

	if (!win_center)
		return (false);
	// data_printer(map);
	map_center = create_vector4(0, 0, 0, 1);
	if (!get_center(map, map_center) || !trans(map, map_center, true, true))
		return (false);
	// data_printer(map);
	if (!init_scale(map))
		return (false);
	// data_printer(map);
	isometic_vector = create_vector4(atan(sqrt(2)), 0, -rad(45), 1);
	if (!rotate(map, isometic_vector, true, false))
		return (false);
	// data_printer(map);
	if (!trans(map, win_center, true, false))
		return (false);
	// data_printer(map);
	return (true);
}

static bool	init_scale(t_map ***map)
{
	int			x;
	int			y;
	double		x_max;
	double		y_max;
	t_vector4	*magnification;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (fabs(map[y][x]->fixed->x) > x_max)
				x_max = fabs(map[y][x]->fixed->x);
			if (fabs(map[y][x]->fixed->y) > y_max)
				y_max = fabs(map[y][x]->fixed->y);
		}
	}
	x_max = (WIDTH / 2 / x_max) * 0.9;
	y_max = (HEIGHT / 2 / y_max) * 0.9;
	// printf("x_max: %.2F, y_max: %.2F\n", x_max, y_max);
	if (x_max < y_max)
		magnification = create_vector4(x_max, x_max, x_max / 4, 1);
	else
		magnification = create_vector4(y_max, y_max, y_max / 4, 1);
	// printf("magnification(%.2F, %.2F, %.2F)\n", magnification->x, magnification->y, magnification->z);
	return (scale(map, magnification, true, false));
}

static int	return_error_int(t_map ***map, char *error_message)
{
	if (map)
		free_map3(map, 0);
	ft_putendl_fd(error_message, 2);
	return (1);
}

// static void	data_printer(t_map ***map)
// {
// 	int		y;
// 	int		x;

// 	if (!map)
// 		return ;
// 	y = 0;
// 	while (map[y])
// 	{
// 		x = 0;
// 		while (map[y][x])
// 		{
// 			printf("(%.2F, %.2F, %.2F) ", map[y][x]->fixed->x,
// 				map[y][x]->fixed->y, map[y][x]->fixed->z);
// 			// ft_printf("(%d, %d, %d) ",(int)(map[y][x]->fixed->x),
// 			// 	(int)(map[y][x]->fixed->y), (int)(map[y][x]->fixed->z));
// 			x++;
// 		}
// 		printf("\n");
// 		// ft_printf("\n");
// 		y++;
// 	}
// 	printf("\n");
// }

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q fdf");
}
