/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:00:34 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/03 15:42:25 by hkoizumi         ###   ########.fr       */
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
			// printf("row_count : %d\n", row_count);
			while (data[row_count][col_count])
			{
				ft_printf("%d ", (int)(data[row_count][col_count]->origin->z));
				col_count++;
			}
			// ft_putchar_fd('\n', 1);
			// printf("\n");
			row_count++;
		}
		free_data(data);
	}
	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q fdf");
}
