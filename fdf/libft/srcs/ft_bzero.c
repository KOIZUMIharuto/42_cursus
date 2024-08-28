/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:16:11 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/19 15:35:49 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	zero_count;

	zero_count = 0;
	if (s)
		while (zero_count < n)
			((unsigned char *)s)[zero_count++] = 0;
}

// #include <string.h>
// #include <stdlib.h>
// #include <stdio.h>

// typedef void	(*t_bzero)(void *, size_t);

// void	test(char **argv, t_bzero bzeroFn, char *Fn_name)
// {
// 	char	*dst;

// 	dst = strdup(argv[1]);
// 	if (dst)
// 	{
// 		printf("%s", Fn_name);
// 		printf("(\"%s\"[%s], %s)", dst, argv[2], argv[3]);
// 		bzeroFn(dst + atoi(argv[2]), (size_t)atoi(argv[3]));
// 		printf(" -> \"%s\"\n", dst);
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
// 		test(argv, bzero, "bzero   ");
// 		test(argv, ft_bzero, "ft_bzero");
// 	}
// 	return (0);
// }
