/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:59:13 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/31 11:51:01 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
