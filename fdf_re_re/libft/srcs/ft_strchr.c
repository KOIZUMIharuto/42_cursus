/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:23:11 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/19 15:42:02 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*((char *)s) == (char)c)
			return ((char *)s);
		s++;
	}
	if (*((char *)s) == (char)c)
		return ((char *)s);
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	if (argc >= 3)
// 	{
// 		printf("strchr    \"%s\" \'%d\' -> ", argv[1], (atoi)(argv[2]));
// 		printf("%s\n", strchr(argv[1], (atoi)(argv[2])));
// 		printf("ft_strchr \"%s\" \'%d\' -> ", argv[1], (atoi)(argv[2]));
// 		printf("%s\n", ft_strchr(argv[1], (atoi)(argv[2])));
// 	}
// 	return (0);
// }
