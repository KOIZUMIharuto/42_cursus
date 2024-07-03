/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:00:34 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/03 16:04:37 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	init_isometric_projection(t_map ***map);
static bool	init_scale(t_map ***map);
static int	return_error_int(t_map ***map, char *error_message, char *option);

int	main(int argc, char **argv)
{
	int			fd;
	t_map		***map;

	if (argc < 2)
		return (return_error_int(NULL, ARG_ERROR_MESSAGE, USAGE));
	if (!ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
		return (return_error_int(NULL, EXTENSION_ERROR_MESSAGE, EXTENTION));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (return_error_int(NULL, strerror(errno), NULL));
	map = get_map(fd, 0);
	close(fd);
	if (!map)
		return (1);
	if (init_isometric_projection(map) == 1)
		return (1);
	my_mlx_main(map);
	free_map3(map, 0, NULL);
	return (0);
}

static int	init_isometric_projection(t_map ***map)
{
	t_vector	*win_center;
	t_vector	*map_center;
	t_vector	*isometic_vector;

	win_center = create_vector4(WIDTH / 2, HEIGHT / 2, 0, 1);
	if (!win_center)
		return (return_error_int(NULL, strerror(errno), NULL));
	map_center = create_vector4(-1, -1, -1, 1);
	if (!map_center)
		return (return_error_int(NULL, strerror(errno), NULL));
	if (!get_center(map, map_center))
	{
		free(map_center);
		free(win_center);
		return (return_error_int(NULL, COLUMN_ERROR_MESSAGE, NULL));
	}
	trans(map, map_center, true, true);
	isometic_vector = create_vector4(atan(sqrt(2)), 0, -rad(45), 1);
	if (!rotate(map, isometic_vector, true, false))
		return (return_error_int(NULL, strerror(errno), NULL));
	if (!init_scale(map))
		return (return_error_int(NULL, SCALE_ERROR_MESSAGE, NULL));
	trans(map, win_center, true, false);
	return (0);
}

static bool	init_scale(t_map ***map)
{
	int			x;
	int			y;
	t_vector	max;

	max = (t_vector){0, 0, 0, 0};
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
	max.x = WIDTH / 2 / max.x * 0.9;
	max.y = HEIGHT / 2 / max.y * 0.9;
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

// __attribute__((destructor))
// static void	destructor(void)
// {
// 	system("leaks -q fdf");
// }