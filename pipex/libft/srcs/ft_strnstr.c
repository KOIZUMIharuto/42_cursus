/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:49:50 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/10/10 14:53:13 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h_count;
	size_t	n_count;

	if (!haystack || !needle)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	h_count = 0;
	while (h_count < len && *haystack)
	{
		n_count = 0;
		while (haystack[n_count] == needle[n_count]
			&& haystack[n_count] && h_count + n_count < len)
			n_count++;
		if (!needle[n_count])
			return ((char *)haystack);
		h_count++;
		haystack++;
	}
	return (NULL);
}
