/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:10:41 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/02/07 15:51:44 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;

	result = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			result = (char *)s;
		s++;
	}
	if (*s == c)
		result = (char *)s;
	return (result);
}

// #include <string.h>
// #include <stdio.h>
// int	main(int argc, char **argv)
// {
// 	if (argc >= 3)
// 	{
// 		printf("strrchr    \"%s\" \'%c\' -> ", argv[1], argv[2][0]);
// 		printf("%s\n", strrchr(argv[1], argv[2][0]));
// 		printf("ft_strrchr \"%s\" \'%c\' -> ", argv[1], argv[2][0]);
// 		printf("%s\n", ft_strrchr(argv[1], argv[2][0]));
// 	}
// 	return (0);
// }
