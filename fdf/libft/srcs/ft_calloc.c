/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:45:07 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/19 15:35:49 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;

	if (count && size && count > SIZE_MAX / size)
		return (NULL);
	dst = (void *)malloc (count * size);
	if (!dst)
		return (NULL);
	ft_bzero(dst, count * size);
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// typedef void	*(*t_calloc)(size_t, size_t);

// void	test(char **argv, t_calloc callocFn, char *Fn_name)
// {
// 	void	*dst;

// 	dst = callocFn(atoi(argv[1]), atoi(argv[2]));
// 	if (dst)
// 	{
// 		printf("%s -> ", Fn_name);
// 		if (!strcmp(argv[3], "char"))
// 			printf("\"%s\"", (char *)dst);
// 		else if (!strcmp(argv[3], "int"))
// 		{
// 			for (int i = 0; i < atoi(argv[1]); i++)
// 			{
// 				if (i == 0)
// 					printf("%d", ((int *)dst)[i]);
// 				else
// 					printf(", %d", ((int *)dst)[i]);
// 			}
// 		}
// 		printf("\n");
// 		free(dst);
// 	}
// 	else
// 	{
// 		printf("the allocation fails\n");
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	char	*test_src[4] = {"test_src", "10", "1", "char"};
// 	if (argc >= 4)
// 	{
// 		test(argv, calloc, "calloc   ");
// 		test(argv, ft_calloc, "ft_calloc");
// 	}
// 	else
// 	{
// 		test(test_src, calloc, "calloc   ");
// 		test(test_src, ft_calloc, "ft_calloc");
// 	}
// 	return (0);
// }
