/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:02:30 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/10/10 14:54:14 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	index;
	int		sign;

	if (!dst || !src)
		return (NULL);
	if (dst <= src)
	{
		index = 0;
		sign = 1;
	}
	else
	{
		index = len - 1;
		sign = -1;
	}
	while (len-- > 0)
	{
		((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
		index += sign;
	}
	return (dst);
}
