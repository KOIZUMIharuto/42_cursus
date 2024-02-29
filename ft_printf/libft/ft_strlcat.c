/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:41:37 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/02/14 14:45:52 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_count;
	size_t	src_count;

	dst_count = 0;
	src_count = 0;
	if (dst || dstsize != 0)
		dst_count = ft_strlen(dst);
	while (dst_count + src_count + 1 < dstsize && src[src_count])
	{
		dst[dst_count + src_count] = src[src_count];
		src_count++;
	}
	if (dst)
		dst[dst_count + src_count] = '\0';
	if (!(!src && dstsize == 0))
		src_count = ft_strlen(src);
	if (dst_count > dstsize)
		return (dstsize + src_count);
	return (dst_count + src_count);
}

// #include <string.h>
// #include <stdlib.h>
// #include <stdio.h>

// typedef size_t	(*t_strlcat)(char *, const char *, size_t);

// void	test(char **argv, t_strlcat strlcatFn, char *Fn_name)
// {
// 	char	*dst;
// 	size_t	len;

// 	dst = (char *)malloc (sizeof(char) * atoi(argv[2]));
// 	if (dst)
// 	{
// 		strcpy(dst, argv[1]);
// 		printf("%s(\"%s\", \"%s\", %d) -> ", Fn_name, dst, argv[3], atoi(argv[4]));
// 		len = strlcatFn(dst, argv[3], atoi(argv[4]));
// 		printf("\"%s\" [%zu]\n", dst, len);
// 		free(dst);
// 	}
// 	else
// 	{
// 		printf("the allocation fails\n");
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	if (argc >= 5)
// 	{
// 		test(argv, strlcat, "strlcat");
// 		test(argv, ft_strlcat, "ft_strlcat");
// 	}
// 	return (0);
// }
