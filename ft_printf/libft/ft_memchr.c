/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:35:54 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/02/07 15:51:21 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	s_count;

	s_count = 0;
	while (s_count < n)
	{
		if (*(char *)s == (char)c)
			return ((void *)s);
		s_count++;
		s++;
	}
	return (NULL);
}

// #include <string.h>
// #include <stdlib.h>
// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	if (argc >= 4)
// 	{
// 		printf("memchr    \"%s\" \'%c\' ", argv[1], argv[2][0]);
// 		printf("[%d] -> ", atoi(argv[3]));
// 		printf("%s\n", memchr(argv[1], argv[2][0], atoi(argv[3])));
// 		printf("ft_memchr \"%s\" \'%c\' ", argv[1], argv[2][0]);
// 		printf("[%d] -> ", atoi(argv[3]));
// 		printf("%s\n", ft_memchr(argv[1], argv[2][0], atoi(argv[3])));
// 	}
// 	return (0);
// }