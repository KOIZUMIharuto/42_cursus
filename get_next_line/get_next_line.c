/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:58:30 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/02/26 16:14:46 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	ssize_t		read_len;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf)
	{
		buf = (char *)malloc ((size_t)BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		buf[0] = '\0';
	}
	read_len = (ssize_t)BUFFER_SIZE;
	line = NULL;
	while (read_len == (ssize_t)BUFFER_SIZE)
		read_len = read_and_join(fd, &buf, &line, read_len);
	if (read_len == -1)
		return (NULL);
	return (line);
}

ssize_t	read_and_join(int fd, char **buf, char **line, ssize_t read_len)
{
	ssize_t	index;
	char	*cut_point;

	if (!(*buf)[0])
	{
		read_len = read (fd, *buf, (size_t)BUFFER_SIZE);
		if (read_len <= 0)
			return (free_all(buf, line, read_len));
		(*buf)[read_len] = '\0';
	}
	cut_point = &(*buf)[count_up_to_0_or_after_nl(*buf)];
	if (*(cut_point - 1) == '\n')
		read_len--;
	*line = join_buf_to_line_up_to_0_or_after_nl(*line, *buf);
	if (!*line)
		return (free_all(buf, line, -1));
	index = -1;
	while (cut_point[++index])
		(*buf)[index] = cut_point[index];
	(*buf)[index] = '\0';
	return (read_len - index);
}

ssize_t	free_all(char **buf, char **line, ssize_t return_value)
{
	if (return_value != 0 || !*line)
	{
		free (*buf);
		*buf = NULL;
	}
	if (return_value == -1 && *line)
		free (*line);
	return (return_value);
}
