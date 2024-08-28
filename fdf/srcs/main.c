/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:00:34 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/27 11:52:02 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static bool	init_isometric_projection(t_map map);
static bool	init_scale(t_map map);
static int	return_msg_int(char *message, char *option);

int	main(int argc, char **argv)
{
	int			fd;
	t_map		map;

	if (argc < 2)
		return (return_msg_int(ARGUMENT_ERROR, USAGE));
	else if (argc > 2)
		ft_putendl_fd(ARGUMENT_WARNING, 1);
	if (!ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
		return (return_msg_int(EXTENSION_ERROR, EXTENTION_REQUIRED));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (return_msg_int(strerror(errno), NULL));
	map = (t_map){-1, -1, NULL};
	get_map(&map, fd, 0);
	close(fd);
	if (!map.dots)
		return (1);
	if (!init_isometric_projection(map))
		return (1);
	copy_vector(map, false);
	my_mlx_main(map);
	free_map(&map);
	return (0);
}

static bool	init_isometric_projection(t_map map)
{
	t_vector	win_center;
	t_vector	map_center;
	t_vector	isometic_vector;

	isometic_vector = (t_vector){atan(sqrt(2)), 0, rad(45)};
	rotate(map, &isometic_vector, false);
	map_center = (t_vector){0, 0, 0};
	get_center(map, &map_center);
	trans(map, &map_center, true, TRANSLATE_CANCEL);
	if (!init_scale(map))
	{
		free_map(&map);
		send_msg(SCALE_ERROR, 2);
		return (false);
	}
	win_center = (t_vector){WIDTH / 2, HEIGHT / 2, 0};
	trans(map, &win_center, false, TRANSLATE_CANCEL);
	return (true);
}

static bool	init_scale(t_map map)
{
	int			x;
	int			y;
	t_vector	max;

	max = (t_vector){0, 0, 0};
	y = -1;
	while (++y < map.y)
	{
		x = -1;
		while (++x < map.x)
		{
			if (fabs(map.dots[y][x].fixed.x) > max.x)
				max.x = fabs(map.dots[y][x].fixed.x);
			if (fabs(map.dots[y][x].fixed.y) > max.y)
				max.y = fabs(map.dots[y][x].fixed.y);
		}
	}
	if (max.x == 0 || max.y == 0)
		return (false);
	max.x = WIDTH / 2 / max.x * INIT_SCALE_RATIO;
	max.y = HEIGHT / 2 / max.y * INIT_SCALE_RATIO;
	if (max.x < max.y)
		return (scale(map, max.x, false));
	else
		return (scale(map, max.y, false));
}

static int	return_msg_int(char *message, char *option)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(message, 2);
	if (option)
		ft_putendl_fd(option, 2);
	return (1);
}
