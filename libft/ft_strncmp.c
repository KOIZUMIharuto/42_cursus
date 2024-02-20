/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:35:16 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/02/07 21:14:11 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cmp_count;

	cmp_count = 0;
	while (cmp_count < n && (s1[cmp_count] || s2[cmp_count]))
	{
		if (s1[cmp_count] != s2[cmp_count])
			return ((unsigned char)s1[cmp_count]
				- (unsigned char)s2[cmp_count]);
		cmp_count++;
	}
	return (0);
}

// #include <string.h>
// #include <stdlib.h>
// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	if (argc >= 4)
// 	{
// 		printf("strncmp    \"%s\" \"%s\" [%d]", argv[1], argv[2], atoi(argv[3]));
// 		printf(" -> %d\n", strncmp(argv[1], argv[2], (size_t)atoi(argv[3])));
// 		printf("ft_strncmp \"%s\" \"%s\" [%d]", argv[1], argv[2], atoi(argv[3]));
// 		printf(" -> %d\n", ft_strncmp(argv[1], argv[2], (size_t)atoi(argv[3])));
// 	}

// 	char *str = "libft-test-tokyo";
// 	char *cmp = "libft-test-tokyo";
// 	int	len = strlen(str);

// 	for (int i = 0; i <= len; i++)
// 	{
// 		cmp = strndup(str, i);
// 		printf("%d i ---------------------------------------------\n", i);
// 		printf("strncmp    \"%s\" \"%s\" [%d]", str, cmp, i);
// 		printf(" -> %d\n", strncmp(str, cmp, i));
// 		printf("ft_strncmp \"%s\" \"%s\" [%d]", str, cmp, i);
// 		printf(" -> %d\n", ft_strncmp(str, cmp, i));
// 		printf("%d len -------------------------------------------\n", i);
// 		printf("strncmp    \"%s\" \"%s\" [%d]", str, cmp, len);
// 		printf(" -> %d\n", strncmp(str, cmp, len));
// 		printf("ft_strncmp \"%s\" \"%s\" [%d]", str, cmp, len);
// 		printf(" -> %d\n", ft_strncmp(str, cmp, len));
// 		free(cmp);
// 	}

// 	return (0);
// }
