/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:58:30 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/02/26 16:14:55 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_fbs	*fbs_list = NULL;
	t_fbs			*fbs;
	ssize_t			r_len;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fbs = find_fd_or_malloc(fd, &fbs_list, fbs_list);
	if (!fbs)
		return (NULL);
	r_len = (ssize_t)BUFFER_SIZE;
	line = NULL;
	while (r_len == (ssize_t)BUFFER_SIZE)
		r_len = read_and_join(fbs, &line, &fbs_list, r_len);
	if (r_len == -1)
		return (NULL);
	return (line);
}

ssize_t	read_and_join(t_fbs *fbs, char **line, t_fbs **fbs_list, ssize_t r_len)
{
	ssize_t	index;
	char	*cut_point;

	if ((fbs->buf)[0] == '\0')
	{
		r_len = read (fbs->fd, fbs->buf, (size_t)BUFFER_SIZE);
		if (r_len <= 0)
			return (free_all(fbs, fbs_list, line, r_len));
		(fbs->buf)[r_len] = '\0';
	}
	cut_point = &(fbs->buf)[count_up_to_0_or_after_nl(fbs->buf)];
	if (*(cut_point - 1) == '\n')
		r_len--;
	*line = join_buf_to_line_up_to_0_or_after_nl(*line, fbs->buf);
	if (!*line)
		return (free_all(fbs, fbs_list, line, -1));
	index = -1;
	while (cut_point[++index])
		(fbs->buf)[index] = cut_point[index];
	(fbs->buf)[index] = '\0';
	return (r_len - index);
}

ssize_t	free_all(t_fbs *fbs, t_fbs **fbs_list, char **line, ssize_t rv)
{
	if (rv != 0 || !*line)
	{
		if (fbs->pre_set)
			fbs->pre_set->after_set = fbs->after_set;
		else
			*fbs_list = fbs->after_set;
		if (fbs->after_set)
			fbs->after_set->pre_set = fbs->pre_set;
		free (fbs->buf);
		fbs->buf = NULL;
		free (fbs);
		fbs = NULL;
	}
	if (rv == -1 && *line)
		free (*line);
	return (rv);
}

t_fbs	*find_fd_or_malloc(int fd, t_fbs **fbs_list, t_fbs *fbs_tmp)
{
	while (fbs_tmp)
	{
		if (fbs_tmp->fd == fd)
			return (fbs_tmp);
		fbs_tmp = fbs_tmp->after_set;
	}
	fbs_tmp = (t_fbs *)malloc (sizeof(t_fbs));
	if (!fbs_tmp)
		return (NULL);
	fbs_tmp->fd = fd;
	fbs_tmp->buf = (char *)malloc ((size_t)BUFFER_SIZE + 1);
	if (!fbs_tmp->buf)
	{
		free (fbs_tmp);
		return (NULL);
	}
	(fbs_tmp->buf)[0] = '\0';
	fbs_tmp->pre_set = NULL;
	fbs_tmp->after_set = *fbs_list;
	if (*fbs_list)
		(*fbs_list)->pre_set = fbs_tmp;
	*fbs_list = fbs_tmp;
	return (fbs_tmp);
}
