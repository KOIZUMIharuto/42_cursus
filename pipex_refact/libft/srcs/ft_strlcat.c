/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:41:37 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/10/10 14:53:30 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_count;
	size_t	src_count;

	dst_count = ft_strlen(dst);
	src_count = 0;
	while (dst_count + src_count + 1 < dstsize && src && src[src_count])
	{
		dst[dst_count + src_count] = src[src_count];
		src_count++;
	}
	if (dst)
		dst[dst_count + src_count] = '\0';
	if (src || dstsize != 0)
		src_count = ft_strlen(src);
	if (dst_count > dstsize)
		return (dstsize + src_count);
	return (dst_count + src_count);
}
