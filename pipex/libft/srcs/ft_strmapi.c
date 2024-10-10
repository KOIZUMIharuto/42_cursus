/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:11:17 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/10/10 14:53:19 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	long	index;
	char	*result;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	result = (char *)malloc ((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	index = -1;
	while (++index < (unsigned int)len)
		result[index] = f((unsigned int)index, s[index]);
	result[index] = '\0';
	return (result);
}
