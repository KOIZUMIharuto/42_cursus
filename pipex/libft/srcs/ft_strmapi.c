/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:11:17 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/31 11:51:01 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	long	index;
	char	*result;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	result = (char *)malloc ((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	index = -1;
	while (++index < (unsigned int)len)
		result[index] = f((unsigned int)index, s[index]);
	result[index] = '\0';
	return (result);
}

// #include <string.h>
// #include <stdio.h>

// char	test(unsigned int index, char c)
// {
// 	if (index % 2 == 0)
// 		return (c + 1);
// 	return (c - 1);
// }

// int	main(int argc, char **argv)
// {
// 	char	*dst;
// 	if (argc >= 2)
// 	{
// 		dst = ft_strmapi(argv[1], test);
// 		if (dst)
// 			{
// 			printf("\"%s\" -> \"%s\"\n", argv[1], dst);
// 			free(dst);
// 		}
// 		else
// 		{
// 			printf("the allocation fails\n");
// 		}
// 	}
// 	return (0);
// }
