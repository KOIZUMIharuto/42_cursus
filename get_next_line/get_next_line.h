/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:59:19 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/02/26 16:14:12 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
ssize_t	read_and_join(int fd, char **buf, char **line, ssize_t read_len);
ssize_t	free_all(char **buf, char **line, ssize_t return_value);
char	*join_buf_to_line_up_to_0_or_after_nl(char *line, char const *buf);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	count_up_to_0_or_after_nl(const char *s);

#endif
