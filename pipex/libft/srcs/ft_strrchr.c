/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:10:41 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/10/10 14:53:08 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*result;

	if (!s)
		return (NULL);
	result = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			result = (char *)s;
		s++;
	}
	if (*s == (unsigned char)c)
		result = (char *)s;
	return (result);
}
