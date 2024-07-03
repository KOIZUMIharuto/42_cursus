/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:58:30 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/31 11:51:01 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static t_f_b	*get_fd_buf_set(int fd, t_f_b **f_b_l, t_f_b *f_b_tmp);
static ssize_t	read_join(t_f_b *f_b, char **line, t_f_b **f_b_l, ssize_t len);
static ssize_t	free_all(t_f_b *f_b, t_f_b **f_b_l, char **line, ssize_t rv);

char	*get_next_line(int fd)
{
	static t_f_b	*f_b_l;
	t_f_b			*f_b;
	ssize_t			len;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	f_b = get_fd_buf_set(fd, &f_b_l, f_b_l);
	if (!f_b)
		return (NULL);
	len = 1;
	line = NULL;
	while (len > 0)
		len = read_join(f_b, &line, &f_b_l, len);
	if (len == -1)
		return (NULL);
	return (line);
}

static t_f_b	*get_fd_buf_set(int fd, t_f_b **f_b_l, t_f_b *f_b_tmp)
{
	while (f_b_tmp)
	{
		if (f_b_tmp->fd == fd)
			return (f_b_tmp);
		f_b_tmp = f_b_tmp->post_set;
	}
	f_b_tmp = (t_f_b *)malloc (sizeof(t_f_b));
	if (!f_b_tmp)
		return (NULL);
	f_b_tmp->fd = fd;
	f_b_tmp->buf = (char *)malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!f_b_tmp->buf)
	{
		free (f_b_tmp);
		return (NULL);
	}
	(f_b_tmp->buf)[0] = '\0';
	f_b_tmp->pre_set = NULL;
	f_b_tmp->post_set = *f_b_l;
	if (*f_b_l)
		(*f_b_l)->pre_set = f_b_tmp;
	*f_b_l = f_b_tmp;
	return (f_b_tmp);
}

static ssize_t	read_join(t_f_b *f_b, char **line, t_f_b **f_b_l, ssize_t len)
{
	ssize_t	index;
	char	*cut_point;

	if ((f_b->buf)[0] == '\0')
	{
		len = read (f_b->fd, f_b->buf, BUFFER_SIZE);
		if (len <= 0)
			return (free_all(f_b, f_b_l, line, len));
		(f_b->buf)[len] = '\0';
	}
	cut_point = &(f_b->buf)[strlen_up_to_c_or_0(f_b->buf, '\n')];
	if (*(cut_point - 1) == '\n')
		len = 0;
	*line = join_up_to_c_or_0(*line, f_b->buf, '\n');
	if (!*line)
		return (free_all(f_b, f_b_l, line, -1));
	index = -1;
	while (cut_point[++index])
		(f_b->buf)[index] = cut_point[index];
	(f_b->buf)[index] = '\0';
	return (len);
}

static ssize_t	free_all(t_f_b *f_b, t_f_b **f_b_l, char **line, ssize_t rv)
{
	if (rv != 0 || !*line)
	{
		if (f_b->pre_set)
			f_b->pre_set->post_set = f_b->post_set;
		else
			*f_b_l = f_b->post_set;
		if (f_b->post_set)
			f_b->post_set->pre_set = f_b->pre_set;
		free (f_b->buf);
		f_b->buf = NULL;
		free (f_b);
		f_b = NULL;
	}
	if (rv == -1 && *line)
		free (*line);
	return (rv);
}
