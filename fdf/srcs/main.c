/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:00:34 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/05/29 12:57:28 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int main(int argc, char **argv)
{
	char	***map;
	int		row_count;
	int		col_count;

	if (argc >=2)
	{
		map = check_map(argv[1], &row_count, &col_count);
		if (!map)
			return (1);
		int i = 0;
		while (i < row_count)
		{
			int j = 0;
			while (j < col_count)
			{
				ft_putstr_fd(map[i][j], 1);
				ft_putchar_fd(':', 1);
				j++;
			}
			ft_putchar_fd('\n', 1);
			i++;
		}
	}
	return (0);
}