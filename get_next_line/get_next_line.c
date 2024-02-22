/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:58:30 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/02/22 12:12:14 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	ssize_t		can_continue_read;
	char		*line;

	if (!buf)
		buf = (char *)gnl_calloc ((size_t)BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	can_continue_read = (size_t)BUFFER_SIZE;
	line = NULL;
	while (can_continue_read == (size_t)BUFFER_SIZE)
		can_continue_read = add_buf_to_line(fd, &buf, &line);
	if (can_continue_read == -1)
		return (NULL);
	return (line);
}

int	add_buf_to_line(int fd, char **buf, char **line)
{
	int		index;
	char	*cut_point;
	ssize_t	did_read_success;

	did_read_success = (size_t)BUFFER_SIZE;
	if ((*buf)[0] == '\0')
	{
		did_read_success = read (fd, *buf, (size_t)BUFFER_SIZE);
		if (did_read_success <= 0)
			return (free_all(buf, line, did_read_success));
		(*buf)[did_read_success] = '\0';
	}
	cut_point = gnl_strchr(*buf);
	if (*cut_point == '\n')
		cut_point++;
	*line = gnl_strjoin(*line, *buf);
	if (!*line)
		return (free_all(buf, line, -1));
	index = -1;
	while (cut_point[++index])
		(*buf)[index] = cut_point[index];
	(*buf)[index] = cut_point[index];
	if (*gnl_strchr(*line) == '\n')
		index++;
	return ((int)did_read_success - index);
}

int	free_all(char **buf, char **line, ssize_t return_value)
{
	if (return_value != 0 || !*line)
	{
		free (*buf);
		*buf = NULL;
	}
	if (return_value == -1 && *line)
		free (*line);
	return ((int)return_value);
}

void	*gnl_calloc(size_t count, size_t size)
{
	void	*dst;
	size_t	zero_count;

	if (count && size && count > SIZE_MAX / size)
		return (NULL);
	dst = (void *)malloc (count * size);
	if (!dst)
		return (NULL);
	zero_count = 0;
	while (zero_count < count * size)
		((unsigned char *)dst)[zero_count++] = '\0';
	return (dst);
}
