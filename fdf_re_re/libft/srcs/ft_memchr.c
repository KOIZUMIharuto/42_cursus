/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:35:54 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/19 15:42:02 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (s && n-- > 0)
	{
		if (*(char *)s == (char)c)
			return ((void *)s);
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