/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:01:25 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/05/29 12:56:38 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	recursive_gnl(char ****map, int fd, int row_count);
static void	free_words(char ***words);

char	***check_map(char *map_file, int *row_count, int *col_count)
{
	int		fd;
	char	***map;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	*row_count = recursive_gnl(&map, fd, 0);
	if (*row_count < 0)
		return (NULL);
	*col_count = 0;
	while (map[0][*col_count])
		(*col_count)++;
	return (map);
}

static int	recursive_gnl(char ****map, int fd, int row_index)
{
	char	*row;
	int		row_count;

	row = get_next_line(fd);
	if (row)
		row_count = recursive_gnl(map, fd, row_index + 1);
	else
	{
		*map = (char ***)malloc ((row_index + 1) * sizeof(char **));
		row_count = row_index;
	}
	if (row_count < 0 || !map)
	{
		free (row);
		return (-1);
	}
	(*map)[row_index] = ft_split(row, " \n");
	free (row);
	if (row && !(*map)[row_index])
	{
		free_words(&((*map)[row_index]));
		return (-1);
	}
	return (row_count);
}

static void	free_words(char ***words)
{
	int	index_1;
	int	index_2;

	index_1 = 0;
	while (words[index_1])
	{
		index_2 = 0;
		while (words[index_1][index_2])
			free (words[index_1][index_2++]);
		index_1++;
	}
}
