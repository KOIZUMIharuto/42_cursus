/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:36:44 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/10/10 14:53:41 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	char_count;

	if (!s1)
		return (NULL);
	char_count = ft_strlen(s1);
	dst = (char *)malloc ((char_count + 1) * sizeof(char));
	if (dst)
		(void)ft_strlcpy(dst, s1, (char_count + 1) * sizeof(char));
	return (dst);
}
