/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:41:37 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/31 11:51:01 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_count;
	size_t	src_count;

	dst_count = ft_strlen(dst);
	src_count = 0;
	while (dst_count + src_count + 1 < dstsize && src && src[src_count])
	{
		dst[dst_count + src_count] = src[src_count];
		src_count++;
	}
	if (dst)
		dst[dst_count + src_count] = '\0';
	if (src || dstsize != 0)
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
// 		strcpy(dst, NULL);
// 		printf("%s(\"%s\", \"%s\", %d) -> ", Fn_name, dst, NULL, atoi(argv[4]));
// 		len = strlcatFn(dst, NULL, atoi(argv[4]));
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
// 	strlcat(NULL, NULL, 0);
// 	return (0);
// }
