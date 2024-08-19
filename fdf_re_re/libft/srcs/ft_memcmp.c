/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:35:16 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/19 15:42:02 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (s1 && s2 && n-- > 0)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	return (0);
}

// #include <string.h>
// #include <stdlib.h>
// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	if (argc >= 4)
// 	{
// 		printf("memcmp    \"%s\" \"%s\" [%d]", argv[1], argv[2], atoi(argv[3]));
// 		printf(" -> %d\n", memcmp(argv[1], argv[2], (size_t)atoi(argv[3])));
// 		printf("ft_memcmp \"%s\" \"%s\" [%d]", argv[1], argv[2], atoi(argv[3]));
// 		printf(" -> %d\n", ft_memcmp(argv[1], argv[2], (size_t)atoi(argv[3])));
// 	}
// 	return (0);
// }
