/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:59:13 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/21 13:13:09 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);

char	*join_up_to_c_or_0(char *line, char *buf, char c)
{
	size_t	len;
	size_t	index;
	char	*dst;

	if (!buf)
		return (NULL);
	len = strlen_up_to_c_or_0(line, c) + strlen_up_to_c_or_0(buf, c);
	dst = (char *)malloc ((len + 1) * sizeof(char));
	if (!dst)
	{
		if (line)
			free (line);
		return (NULL);
	}
	index = 0;
	if (line)
	{
		index += ft_strlcpy(dst, line, (len + 1) * sizeof(char));
		free (line);
	}
	index += ft_strlcpy(&dst[index], buf, (len - index + 1) * sizeof(char));
	dst[len] = '\0';
	return (dst);
}

size_t	strlen_up_to_c_or_0(char *s, char c)
{
	size_t	len;

	len = 0;
	if (s)
		while (s[len])
			if (s[len++] == c)
				return (len);
	return (len);
}

static size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	cpy_count;

	cpy_count = 0;
	if (dstsize != 0)
	{
		while (src[cpy_count] && cpy_count + 1 < dstsize)
		{
			dst[cpy_count] = src[cpy_count];
			cpy_count++;
		}
		dst[cpy_count] = '\0';
	}
	return (cpy_count);
}
