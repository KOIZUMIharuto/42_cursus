/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:09:43 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/10/10 14:52:58 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dst;
	unsigned int	start_count;
	size_t			len_count;

	start_count = 0;
	if (!s)
		return (NULL);
	while (start_count++ < start && *s)
		s++;
	len_count = 0;
	while (len_count < len && s[len_count])
		len_count++;
	dst = (char *)malloc ((len_count + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	(void)ft_strlcpy (dst, s, (len_count + 1) * sizeof(char));
	return (dst);
}
