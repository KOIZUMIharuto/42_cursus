/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:00:38 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/31 11:51:01 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	set_count;

	set_count = 0;
	while (set_count < len)
		((unsigned char *)b)[set_count++] = (unsigned char)c;
	return (b);
}

// #include <string.h>
// #include <stdlib.h>
// #include <stdio.h>

// typedef void	*(*t_memset)(void *, int, size_t);

// void	test(char **argv, t_memset memsetFn, char *Fn_name)
// {
// 	char	*dst = strdup(argv[1]);
// 	printf("%s", Fn_name);
// 	printf("(\"%s\"[%s], '%c', %s)", dst, argv[2], argv[3][0], argv[4]);
// 	memsetFn(dst + atoi(argv[2]), argv[3][0], (size_t)atoi(argv[4]));
// 	printf(" -> \"%s\"\n", dst);
// 	free(dst);
// }

// int	main(int argc, char **argv)
// {
// 	if (argc >= 5)
// 	{
// 		test(argv, memset, "memset   ");
// 		test(argv, ft_memset, "ft_memset");
// 	}
// 	return (0);
// }
