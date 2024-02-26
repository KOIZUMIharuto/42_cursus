/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:59:19 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/02/26 16:19:25 by hkoizumi         ###   ########.fr       */
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
	struct s_fbs	*after_set;
}	t_fbs;

char	*get_next_line(int fd);
ssize_t	read_and_join(t_fbs *fbs, char **line, t_fbs **fbs_list, ssize_t r_len);
ssize_t	free_all(t_fbs *fbs, t_fbs **fbs_list, char **line, ssize_t rv);
char	*join_buf_to_line_up_to_0_or_after_nl(char *line, char const *buf);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	count_up_to_0_or_after_nl(const char *s);
t_fbs	*find_fd_or_malloc(int fd, t_fbs **fbs_list, t_fbs *fbs_tmp);

#endif
