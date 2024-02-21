/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:59:19 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/02/21 18:58:14 by hkoizumi         ###   ########.fr       */
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
int		add_buf_to_line(int fd, char *buf, char **line);
int		free_all(char *buf, char **line, ssize_t return_value);
void	*gnl_calloc(size_t count, size_t size);
char	*gnl_strjoin(char *s1, char const *s2);
size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize);
char	*gnl_strchr(const char *s);
size_t	gnl_strlen(const char *s);

#endif