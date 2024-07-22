/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:53:20 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/04/19 16:38:23 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	index;

	index = 0;
	if (!dst || !src)
		return (NULL);
	while (index < n)
	{
		((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
		index++;
	}
	return (dst);
}

// #include <string.h>
// #include <stdlib.h>
// #include <stdio.h>

// typedef void	*(*t_memcpy)(void *restrict, const void *restrict, size_t);

// void	test(char **argv, t_memcpy memcpyFn, char *Fn_name)
// {
// 	char	*dst;

// 	dst = (char *)malloc (sizeof(char) * atoi(argv[1]));
// 	if (!dst)
// 		return ;
// 	for (int i = 0; i < atoi(argv[1]); i++)
// 		dst[i] = '\0';
// 	printf("%s(dst, \"%s\", %d) ", Fn_name, argv[2], atoi(argv[3]));
// 	if (Fn_name[0] != 'f')
// 		printf("   ");
// 	memcpyFn(NULL, NULL, atoi(argv[3]));
// 	printf("-> \"%s\"\n", dst);
// 	free(dst);
// }

// int	main(int argc, char **argv)
// {
// 	if (argc >= 4)
// 	{
// 		test(argv, memcpy, "memcpy");
// 		test(argv, ft_memcpy, "ft_memcpy");
// 	}
// 	return (0);
// }
