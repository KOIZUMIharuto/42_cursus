/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:00:34 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/05 14:40:29 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	return_error_int(char *error_message);
static void	data_printer(t_data ***data);

int	main(int argc, char **argv)
{
	int		x;
	int		y;
	t_data	***data;

	if (argc < 2)
		return (return_error_int(USAGE_ERROR_MESSAGE));
	data = get_map_data(argv[1]);
	if (!data)
		return (1);
	if (x_y_counter(data, &x, &y))
	{
	}
	data_printer(data);
	free_data3(data, 0);
	return (0);
}

static int	return_error_int(char *error_message)
{
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
			ft_printf("%d ", (int)(data[y][x]->origin->z));
			x++;
		}
		ft_printf("\n");
		y++;
	}
}

__attribute__((destructor))
static void	destructor(void)
{
	system("leaks -q fdf");
}
