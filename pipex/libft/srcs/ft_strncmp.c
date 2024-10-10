/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:35:16 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/10/10 14:52:39 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cmp_count;

	cmp_count = 0;
	if (!s1 || !s2)
		return ((int)(s1 - s2));
	while (cmp_count < n && (s1[cmp_count] || s2[cmp_count]))
	{
		if (s1[cmp_count] != s2[cmp_count])
			return ((unsigned char)s1[cmp_count]
				- (unsigned char)s2[cmp_count]);
		cmp_count++;
	}
	return (0);
}
