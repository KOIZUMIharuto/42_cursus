/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:00:34 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/07 00:32:48 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static bool	init_isometric_projection(t_data ***data, t_vector4 *win_center);
static bool	init_scale(t_data ***data);
static int	return_error_int(t_data ***data, char *error_message);
static void	data_printer(t_data ***data);

int	main(int argc, char **argv)
{
	t_data		***data;
	t_vector4	*win_center;

	if (argc < 2)
		return (return_error_int(NULL, USAGE_ERROR_MESSAGE));
	data = get_map(argv[1]);
	if (!data)
		return (1);
	win_center = create_vector4(WIDTH / 2, HIGHT / 2, 0, 1);
	if (!init_isometric_projection(data, win_center))
		return (1);
	free_data3(data, 0);
	return (0);
}

static bool	init_isometric_projection(t_data ***data, t_vector4 *win_center)
{
	t_vector4	*map_center;
	t_vector4	*isometic_vector;

	if (!win_center)
		return (false);
	data_printer(data);
	map_center = create_vector4(0, 0, 0, 1);
	if (!get_center(data, map_center) || !trans(data, map_center, true, true))
		return (false);
	data_printer(data);
	isometic_vector = create_vector4(atan(sqrt(2)), 0, rad(45), 1);
	if (!rotate(data, isometic_vector, true, false))
		return (false);
	data_printer(data);
	if (!init_scale(data))
		return (false);
	data_printer(data);
	if (!trans(data, win_center, true, true))
		return (false);
	data_printer(data);
	return (true);
}

static bool	init_scale(t_data ***data)
{
	int			x;
	int			y;
	double		x_max;
	double		y_max;
	t_vector4	*magnification;

	y = -1;
	while (data[++y])
	{
		x = -1;
		while (data[y][++x])
		{
			if (fabs(data[y][x]->fixed->x) > x_max)
				x_max = fabs(data[y][x]->fixed->x);
			if (fabs(data[y][x]->fixed->y) > y_max)
				y_max = fabs(data[y][x]->fixed->y);
		}
	}
	x_max = WIDTH / 2 / x_max;
	y_max = HIGHT / 2 / y_max;
	printf("x_max: %.2F, y_max: %.2F\n", x_max, y_max);
	if (x_max < y_max)
		magnification = create_vector4(x_max, x_max, x_max, 1);
	else
		magnification = create_vector4(y_max, y_max, y_max, 1);
	printf("magnification(%.2F, %.2F, %.2F)\n", magnification->x, magnification->y, magnification->z);
	return (scale(data, magnification, true, false));
}

static int	return_error_int(t_data ***data, char *error_message)
{
	if (data)
		free_data3(data, 0);
	ft_putendl_fd(error_message, 2);
	return (1);
}

static void	data_printer(t_data ***data)
{
	int		y;
	int		x;

	if (!data)
		return ;
	y = 0;
	while (data[y])
	{
		x = 0;
		while (data[y][x])
		{
			printf("(%.2F, %.2F, %.2F) ", data[y][x]->fixed->x,
				data[y][x]->fixed->y, data[y][x]->fixed->z);
			// ft_printf("(%d, %d, %d) ",(int)(data[y][x]->fixed->x),
			// 	(int)(data[y][x]->fixed->y), (int)(data[y][x]->fixed->z));
			x++;
		}
		printf("\n");
		// ft_printf("\n");
		y++;
	}
	printf("\n");
}

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q fdf");
}
