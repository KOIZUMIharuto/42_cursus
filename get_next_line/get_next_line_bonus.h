/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:59:19 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/02/22 17:06:29 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_fbs
{
	int				fd;
	char			*buf;
	struct s_fbs	*pre_set;
	struct s_fbs	*post_set;
}	t_fbs;

char		*get_next_line(int fd);
int			buf_to_line(t_fbs *fbs, char **line, t_fbs **fbs_list);
int			free_all(t_fbs *fbs, t_fbs **fbs_list, char **line, ssize_t rv);
void		*gnl_calloc(size_t count, size_t size);
char		*gnl_strjoin(char *s1, char const *s2);
size_t		gnl_strlcpy(char *dst, const char *src, size_t dstsize);
char		*gnl_strchr(const char *s);
size_t		gnl_strlen(const char *s);
t_fbs		*check_set(int fd, t_fbs **fbs_list);

#endif
