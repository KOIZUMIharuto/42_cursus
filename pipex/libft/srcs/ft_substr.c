/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:09:43 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/03 15:52:28 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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

// #include <string.h>
// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	char	*dst;

// 	if (argc >= 4)
// 	{
// 		dst = ft_substr(NULL, atoi(argv[2]), (size_t)atol(argv[3]));
// 		if (dst)
// 		{
// 			printf("ft_substr(\"%s\", %s, %s) -> ", argv[1], argv[2], argv[3]);
// 			printf("\"%s\"\n", dst);
// 			free(dst);
// 		}
// 		else
// 		{
// 			printf("the allocation fails\n");
// 		}
// 	}
// 	return (0);
// }
