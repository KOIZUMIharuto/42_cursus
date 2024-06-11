/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:00:34 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/11 13:28:46 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static bool	init_isometric_projection(t_map ***map, t_vector *win_center);
static bool	init_scale(t_map ***map);
static int	return_error_int(t_map ***map, char *error_message);

int	main(int argc, char **argv)
{
	t_map		***map;
	t_vector	*win_center;

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

static bool	init_isometric_projection(t_map ***map, t_vector *win_center)
{
	t_vector	*map_center;
	t_vector	*isometic_vector;

	if (!win_center)
		return (false);
	map_center = create_vector4(0, 0, 0, 1);
	if (!get_center(map, map_center) || !translate(map, map_center, true, true))
		return (false);
	isometic_vector = create_vector4(atan(sqrt(2)), 0, -rad(45), 1);
	if (!rotate(map, isometic_vector, true, false))
		return (false);
	if (!init_scale(map))
		return (false);
	if (!translate(map, win_center, true, false))
		return (false);
	return (true);
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

static int	return_error_int(t_map ***map, char *error_message)
{
	if (map)
		free_map3(map, 0);
	ft_putendl_fd(error_message, 2);
	return (1);
}

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q fdf");
}
