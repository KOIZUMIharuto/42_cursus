/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:58:30 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/21 13:13:09 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	read_join(int fd, char **buf, char **line, ssize_t read_len);
static ssize_t	free_all(char **buf, char **line, ssize_t return_value);

char	*get_next_line(int fd)
{
	static char	*buf;
	ssize_t		read_len;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf)
	{
		buf = (char *)malloc (sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
		buf[0] = '\0';
	}
	read_len = 1;
	line = NULL;
	while (read_len > 0)
		read_len = read_join(fd, &buf, &line, read_len);
	if (read_len == -1)
		return (NULL);
	return (line);
}

static ssize_t	read_join(int fd, char **buf, char **line, ssize_t read_len)
{
	ssize_t	index;
	char	*cut_point;

	if (!(*buf)[0])
	{
		read_len = read (fd, *buf, BUFFER_SIZE);
		if (read_len <= 0)
			return (free_all(buf, line, read_len));
		(*buf)[read_len] = '\0';
	}
	cut_point = &(*buf)[strlen_up_to_c_or_0(*buf, '\n')];
	if (*(cut_point - 1) == '\n')
		read_len = 0;
	*line = join_up_to_c_or_0(*line, *buf, '\n');
	if (!*line)
		return (free_all(buf, line, -1));
	index = -1;
	while (cut_point[++index])
		(*buf)[index] = cut_point[index];
	(*buf)[index] = '\0';
	return (read_len);
}

static ssize_t	free_all(char **buf, char **line, ssize_t return_value)
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
