/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:00:34 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/29 16:11:14 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	init_isometric_projection(t_list *map);
static bool	init_scale(t_list *map);
static int	return_error_int(t_list *map, char *error_message, char *option);

int	main(int argc, char **argv)
{
	int		fd;
	t_list	*map;

	if (argc < 2)
		return (return_error_int(NULL, ARGUMENT_ERROR, USAGE));
	else if (argc > 2)
		ft_putendl_fd(ARGUMENT_WARNING, 1);
	if (!ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
		return (return_error_int(NULL, EXTENSION_ERROR, EXTENTION));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (return_error_int(NULL, strerror(errno), NULL));
	map = NULL;
	get_map(&map, fd);
	close(fd);
	if (!map)
		return (1);
	if (init_isometric_projection(map) == 1)
		return (1);
	copy_vector(map, false);
	my_mlx_main(map);
	ft_lstclear(&map, &free_map);
	return (0);
}

static int	init_isometric_projection(t_list *map)
{
	t_vector	win_center;
	t_vector	map_center;
	t_vector	isometic_vector;

	isometic_vector = (t_vector){atan(sqrt(2)), 0, rad(45)};
	rotate(map, &isometic_vector, false);
	map_center = (t_vector){0, 0, 0};
	get_center(map, &map_center);
	trans(map, &map_center, true);
	if (!init_scale(map))
		return (return_error_int(NULL, SCALE_ERROR, NULL));
	win_center = (t_vector){WIDTH / 2, HEIGHT / 2, 0};
	trans(map, &win_center, false);
	return (0);
}

static bool	init_scale(t_list *map)
{
	t_list		*row;
	t_dot		*dot;
	double		ratio;
	t_vector	max;

	max = (t_vector){0, 0, 0};
	while (map)
	{
		row = (t_list *)(map->content);
		while (row)
		{
			dot = (t_dot *)(row->content);
			if (fabs(dot->fixed.x) > max.x)
				max.x = fabs(dot->fixed.x);
			if (fabs(dot->fixed.y) > max.y)
				max.y = fabs(dot->fixed.y);
			row = row->next;
		}
		map = map->next;
	}
	ratio = 0.9;
	max.x = WIDTH / 2 / max.x * ratio;
	max.y = HEIGHT / 2 / max.y * ratio;
	if (max.x < max.y)
		return (scale(map, max.x, false));
	else
		return (scale(map, max.y, false));
}

static int	return_error_int(t_list *map, char *error_message, char *option)
{
	if (map)
		ft_lstclear(&map, &free_map);
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(error_message, 2);
	if (option)
		ft_putendl_fd(option, 2);
	return (1);
}
