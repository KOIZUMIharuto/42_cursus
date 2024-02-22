/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:58:30 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/02/22 16:20:29 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_fbs	*fbs_list = NULL;
	t_fbs			*fbs;
	ssize_t			can_continue_read;
	char			*line;

	fbs = check_set(fd, &fbs_list);
	if (!fbs)
		return (NULL);
	can_continue_read = (size_t)BUFFER_SIZE;
	line = NULL;
	while (can_continue_read == (size_t)BUFFER_SIZE)
		can_continue_read = buf_to_line(fbs, &line, &fbs_list);
	if (can_continue_read == -1)
		return (NULL);
	return (line);
}

int	buf_to_line(t_fbs *fbs, char **line, t_fbs **fbs_list)
{
	int		index;
	char	*cut_point;
	ssize_t	is_success;

	is_success = (size_t)BUFFER_SIZE;
	if ((fbs->buf)[0] == '\0')
	{
		is_success = read (fbs->fd, fbs->buf, (size_t)BUFFER_SIZE);
		if (is_success <= 0)
			return (free_all(fbs, fbs_list, line, is_success));
		(fbs->buf)[is_success] = '\0';
	}
	cut_point = gnl_strchr(fbs->buf);
	if (*cut_point == '\n')
		cut_point++;
	*line = gnl_strjoin(*line, fbs->buf);
	if (!*line)
		return (free_all(fbs, fbs_list, line, -1));
	index = -1;
	while (cut_point[++index])
		(fbs->buf)[index] = cut_point[index];
	(fbs->buf)[index] = cut_point[index];
	if (*gnl_strchr(*line) == '\n')
		index++;
	return ((int)is_success - index);
}

int	free_all(t_fbs *fbs, t_fbs **fbs_list, char **line, ssize_t rv)
{	
	if (rv != 0 || !*line)
	{
		if (fbs->pre_set)
			fbs->pre_set->post_set = fbs->post_set;
		else
			*fbs_list = fbs->post_set;
		if (fbs->post_set)
			fbs->post_set->pre_set = fbs->pre_set;
		free (fbs->buf);
		free (fbs);
	}
	if (rv == -1 && *line)
		free (*line);
	return ((int)rv);
}

t_fbs	*check_set(int fd, t_fbs **fbs_list)
{
	t_fbs	*fbs_tmp;

	fbs_tmp = *fbs_list;
	while (fbs_tmp)
	{
		if (fbs_tmp->fd == fd)
			return (fbs_tmp);
		fbs_tmp = fbs_tmp->post_set;
	}
	fbs_tmp = (t_fbs *)malloc (sizeof(t_fbs));
	if (!fbs_tmp)
		return (NULL);
	fbs_tmp->fd = fd;
	fbs_tmp->buf = (char *)gnl_calloc ((size_t)BUFFER_SIZE + 1, sizeof(char));
	if (!fbs_tmp->buf)
	{
		free (fbs_tmp);
		return (NULL);
	}
	fbs_tmp->pre_set = NULL;
	fbs_tmp->post_set = *fbs_list;
	if (*fbs_list)
		(*fbs_list)->pre_set = fbs_tmp;
	*fbs_list = fbs_tmp;
	return (fbs_tmp);
}
