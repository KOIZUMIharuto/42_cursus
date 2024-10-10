/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:23:11 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/10/10 14:53:45 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*((char *)s) == (char)c)
			return ((char *)s);
		s++;
	}
	if (*((char *)s) == (char)c)
		return ((char *)s);
	return (NULL);
}
