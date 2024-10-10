/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:56:38 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/10/10 14:53:26 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	cpy_count;

	if (!dst || !src)
		return (0);
	if (dstsize != 0)
	{
		cpy_count = 0;
		while (src[cpy_count] && cpy_count + 1 < dstsize)
		{
			dst[cpy_count] = src[cpy_count];
			cpy_count++;
		}
		dst[cpy_count] = '\0';
	}
	return (ft_strlen(src));
}
