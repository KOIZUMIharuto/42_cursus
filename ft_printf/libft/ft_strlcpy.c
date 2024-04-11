/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:56:38 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/02/15 16:47:50 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	cpy_count;

	cpy_count = 0;
	if (dstsize != 0)
	{
		while (src[cpy_count] && cpy_count + 1 < dstsize)
		{
			dst[cpy_count] = src[cpy_count];
			cpy_count++;
		}
		dst[cpy_count] = '\0';
	}
	cpy_count = ft_strlen(src);
	return (cpy_count);
}

// #include <string.h>
// #include <stdlib.h>
// #include <stdio.h>

// typedef size_t	(*t_strlcpy)(char *, const char *, size_t);

// void	test(char **argv, t_strlcpy strlcpyFn, char *Fn_name)
// {
// 	char	*dst;
// 	size_t	len;

// 	dst = strdup(argv[1]);
// 	if (dst)
// 	{
// 		printf("%s(\"%s\", \"%s\", %d) ", Fn_name, dst, argv[2], atoi(argv[3]));
// 		len = strlcpyFn(dst, argv[2], atoi(argv[3]));
// 		printf("-> \"%s\" [%zu]\n", dst, len);
// 		free(dst);
// 	}
// 	else
// 	{
// 		printf("the allocation fails\n");
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	if (argc >= 4)
// 	{
// 		test(argv, strlcpy, "strlcpy   ");
// 		test(argv, ft_strlcpy, "ft_strlcpy");
// 	}
// 	return (0);
// }
