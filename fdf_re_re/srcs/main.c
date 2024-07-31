/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:00:34 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/31 14:01:29 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	init_isometric_projection(t_map ***map);
static bool	init_scale(t_map ***map);
static int	return_error_int(t_map ***map, char *error_message, char *option);

int	main(int argc, char **argv)
{
	int			fd;
	t_map		map;

	if (argc < 2)
		return (return_error_int(NULL, ARGUMENT_ERROR, USAGE));
	else if (argc > 2)
		ft_putendl_fd(ARGUMENT_WARNING, 1);
	if (!ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
		return (return_error_int(NULL, EXTENSION_ERROR, EXTENTION_REQUIRED));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (return_error_int(NULL, strerror(errno), NULL));
	map = (t_map){NULL, 0, 0};
	get_map(&map, fd, 0);
	close(fd);
	if (!map.dots)
		return (1);
	if (init_isometric_projection(map) == 1)
		return (1);
	copy_vector(map, false);
	my_mlx_main(map);
	free_map3(map, 0, NULL);
	return (0);
}

static int	init_isometric_projection(t_map ***map)
{
	t_vector	*win_center;
	t_vector	*map_center;
	t_vector	*isometic_vector;

	isometic_vector = create_vector(atan(sqrt(2)), 0, rad(45));
	if (!rotate(map, isometic_vector, true, false))
		return (return_error_int(NULL, strerror(errno), NULL));
	map_center = create_vector(0, 0, 0);
	if (!map_center)
		return (return_error_int(NULL, strerror(errno), NULL));
	if (!get_center(map, map_center))
	{
		free(map_center);
		return (return_error_int(NULL, COLUMN_ERROR, NULL));
	}
	trans(map, map_center, true, true);
	if (!init_scale(map))
		return (return_error_int(NULL, SCALE_ERROR, NULL));
	win_center = create_vector(WIDTH / 2, HEIGHT / 2, 0);
	if (!win_center)
		return (return_error_int(NULL, strerror(errno), NULL));
	trans(map, win_center, true, false);
	return (0);
}

static bool	init_scale(t_map ***map)
{
	int			x;
	int			y;
	double		ratio;
	t_vector	max;

	max = (t_vector){0, 0, 0};
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (fabs(map[y][x]->fixed->x) > max.x)
				max.x = fabs(map[y][x]->fixed->x);
			if (fabs(map[y][x]->fixed->y) > max.y)
				max.y = fabs(map[y][x]->fixed->y);
		}
	}
	ratio = 0.9;
	max.x = WIDTH / 2 / max.x * ratio;
	max.y = HEIGHT / 2 / max.y * ratio;
	if (max.x < max.y)
		return (scale(map, max.x, false));
	else
		return (scale(map, max.y, false));
}

static int	return_error_int(t_map ***map, char *error_message, char *option)
{
	if (map)
		free_map3(map, 0, NULL);
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(error_message, 2);
	if (option)
		ft_putendl_fd(option, 2);
	return (1);
}
