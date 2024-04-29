/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:49:50 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/31 11:51:01 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h_count;
	size_t	n_count;

	if (!haystack || !needle)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	h_count = 0;
	while (h_count < len && *haystack)
	{
		n_count = 0;
		while (haystack[n_count] == needle[n_count]
			&& haystack[n_count] && h_count + n_count < len)
			n_count++;
		if (!needle[n_count])
			return ((char *)haystack);
		h_count++;
		haystack++;
	}
	return (NULL);
}

// #include <string.h>
// #include <stdlib.h>
// #include <stdio.h>

// void test(char *str, char *cmp, int i)
// {
// 	printf("strnstr    \"%s\" \"%s\" [%d] ", str, cmp, i);
// 	printf("-> \"%s\"\n", strnstr(str, cmp, i));
// 	printf("ft_strnstr \"%s\" \"%s\" [%d] ", str, cmp, i);
// 	printf("-> \"%s\"\n", ft_strnstr(str, cmp, i));
// }
// int	main(void)
// {
// 	char *str = "libft-test-tokyo";
// 	int	len = strlen(str);
// 	for (int i = 0; i < len; i++)
// 	{
// 		printf("==========================================================\n");
// 		test(str, "", i);
// 		test(str, "libft-test-tokyo", i);
// 		test(str, "libft", i);
// 		test(str, "test", i);
// 		test(str, "tokyo", i);
// 		test(str, "libft~", i);
// 		test(str, "z", i);
// 		printf("\n\n\n");
// 	}
// 	return (0);
// }
