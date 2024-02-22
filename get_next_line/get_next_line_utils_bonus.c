/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:59:13 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/02/22 15:22:05 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(char *s1, char const *s2)
{
	size_t	len;
	size_t	index;
	char	*dst;

	if (!s1 && !s2)
		return (NULL);
	len = gnl_strlen(s1) + gnl_strlen(s2);
	dst = (char *)malloc ((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	index = 0;
	if (s1)
	{
		index += gnl_strlcpy(dst, s1, (len + 1) * sizeof(char));
		free (s1);
	}
	if (s2)
		index += gnl_strlcpy(&dst[index], s2, (len - index + 1) * sizeof(char));
	dst[len] = '\0';
	return (dst);
}

size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize)
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
	while (src[cpy_count])
		cpy_count++;
	return (cpy_count);
}

char	*gnl_strchr(const char *s)
{
	if (s)
	{
		while (*s)
		{
			if (*s == '\n')
				return ((char *)s);
			s++;
		}
		return ((char *)s);
	}
	return (NULL);
}

size_t	gnl_strlen(const char *s)
{
	size_t	len;
	char	*s_end;

	len = 0;
	if (s)
	{
		s_end = gnl_strchr(s);
		if (s_end[0] == '\n')
			s_end++;
		while (&s[len] < s_end)
			len++;
	}
	return (len);
}

void	*gnl_calloc(size_t count, size_t size)
{
	void	*dst;
	size_t	zero_count;

	if (count && size && count > SIZE_MAX / size)
		return (NULL);
	dst = (void *)malloc (count * size);
	if (!dst)
		return (NULL);
	zero_count = 0;
	while (zero_count < count * size)
		((unsigned char *)dst)[zero_count++] = '\0';
	return (dst);
}
