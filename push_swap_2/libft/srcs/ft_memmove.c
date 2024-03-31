/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:02:30 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/31 11:51:01 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	index;
	int		sign;

	if (!dst || !src)
		return (NULL);
	if (dst <= src)
	{
		index = 0;
		sign = 1;
	}
	else
	{
		index = len - 1;
		sign = -1;
	}
	while (len-- > 0)
	{
		((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
		index += sign;
	}
	return (dst);
}

// #include <string.h>
// #include <stdlib.h>
// #include <stdio.h>

// typedef void	*(*t_memmove)(void *, const void *, size_t);

// // "./a.out test_1 dstlen src cpylen"
// void	test_1(char **argv, t_memmove memmoveFn, char *Fn_name)
// {
// 	char	*dst = (char *)malloc (sizeof(char) * atoi(argv[2]));
// 	if (!dst)
// 		return ;
// 	for (int i = 0; i < atoi(argv[2]); i++)
// 		dst[i] = '\0';
// 	printf("%s(dst, \"%s\", %d) ", Fn_name, argv[3], atoi(argv[4]));
// 	memmoveFn(dst, argv[3], (size_t)(atoi(argv[4])));
// 	printf("-> \"%s\"\n", dst);
// 	free(dst);
// }

// // "./a.out test_2 src to from cpylen"
// void	test_2(char **argv, t_memmove memmoveFn, char *Fn_name)
// {
// 	char	*dst = strdup(argv[2]);
// 	if (!dst)
// 		return ;
// 	printf("%s : \"%s\" -> ", Fn_name, dst);
// 	memmoveFn(&(dst[(atoi(argv[3]))]), &(dst[(atoi(argv[4]))]), atoi(argv[5]));
// 	printf("\"%s\"\n", dst);
// 	free(dst);
// }

// int	main(int argc, char **argv)
// {
// 	if (argc >= 5)
// 	{
// 		if (!strcmp(argv[1], "test_1"))
// 		{
// 			test_1(argv, memmove, "memmove   ");
// 			test_1(argv, ft_memmove, "ft_memmove");
// 		}
// 		else if (!strcmp(argv[1], "test_2") && argc >= 6)
// 		{
// 			test_2(argv, memmove, "memmove   ");
// 			test_2(argv, ft_memmove, "ft_memmove");
// 		}
// 	}
// 	return (0);
// }
