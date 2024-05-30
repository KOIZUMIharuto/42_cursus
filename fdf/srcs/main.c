/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:00:34 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/05/30 15:51:59 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	int		row_count;
	int		col_count;
	t_data	***data;

	if (argc >= 2)
	{
		data = get_map_data(argv[1]);
		if (!data)
			return (1);
		row_count = 0;
		while (data[row_count])
		{
			col_count = 0;
			ft_putstr_fd("! ", 1);
			while (data[row_count][col_count])
			{
				ft_printf("%d ", data[row_count][col_count]->z);
				free (data[row_count][col_count]);
				col_count++;
			}
			free(data[row_count]);
			ft_putchar_fd('\n', 1);
			row_count++;
		}
		free (data);
	}
	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q fdf");
}
