/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:59:13 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/02/26 16:30:10 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_buf_to_line_up_to_0_or_after_nl(char *line, char const *buf)
{
	size_t	len;
	size_t	index;
	char	*dst;

	if (!buf)
		return (NULL);
	len = count_up_to_0_or_after_nl(line) + count_up_to_0_or_after_nl(buf);
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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
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

size_t	count_up_to_0_or_after_nl(const char *s)
{
	size_t	len;

	len = 0;
	if (s)
		while (s[len])
			if (s[len++] == '\n')
				return (len);
	return (len);
}
