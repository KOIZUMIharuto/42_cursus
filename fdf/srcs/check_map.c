/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:01:25 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/05/24 14:55:55 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	recursive_gnl(char ****input, int fd, int row_count);

char	***check_map(char *map_file)
{
	int		fd;
	int		row_count;
	char	**input;
	char	***map;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	row_count = recursive_gnl(&input, fd, 0);
	if (row_count < 0)
		return (NULL);
	map = (char	***)malloc ((row_count + 1) * sizeof(char **));
	if (!map)
	{
		while (--row_count >= 0)
			free (input[row_count]);
		free (input);
		return (NULL);
	}
	while (row_count >= 0)
	{
		map[row_count] = ft_split(input[row_count], ' ');
		free (input[row_count--]);
	}

}

static int	recursive_gnl(char ****input, int fd, int row_index)
{
	char	*row;
	int		row_count;

	row = get_next_line(fd);
	if (row)
	{
		row_count = recursive_gnl(input, fd, row_index + 1);
		if (row_count < 0)
		{
			free (row);
			return (-1);
		}
		(*input)[row_index] = ft_split(row, ' ');
		free (row);
	}
	else
	{
		*input = (char ***)malloc ((row_index + 1) * sizeof(char **));
		if (!*input)
			return (-1);
		row_count = row_index;
		(*input)[row_index] = NULL;
	}
	return (row_count);
}

void	free_words(char ***words)
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