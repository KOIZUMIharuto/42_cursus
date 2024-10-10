/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:05:39 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/10/10 14:53:03 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

bool	set_checker(char const c, char const *set)
{
	if (!set)
		return (false);
	while (*set)
		if (c == *(set++))
			return (true);
	return (false);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	safe_count;
	char	*dst;

	if (!s1)
		return (NULL);
	while (set_checker(*s1, set) && *s1)
		s1++;
	len = 0;
	safe_count = 0;
	while (s1[len + safe_count])
	{
		len += safe_count;
		while (!set_checker(s1[len], set) && s1[len])
			len++;
		safe_count = 0;
		while (set_checker(s1[len + safe_count], set) && s1[len + safe_count])
			safe_count++;
	}
	dst = (char *)malloc ((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	(void)ft_strlcpy (dst, s1, (len + 1) * sizeof(char));
	return (dst);
}
