/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:55:54 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/05/24 12:36:30 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	**recursive_split(char *str, char c, int words_count);

char	**ft_split(char const *str, char c)
{
	char	**words;

	if (!str)
		return (NULL);
	words = recursive_split((char *)str, c, 0);
	return (words);
}

static char	**recursive_split(char *str, char c, int words_count)
{
	int		len;
	char	**words;

	while (*str && *str == c)
		str++;
	len = 0;
	while (*str && str[len] && str[len] != c)
		len++;
	if (*str)
		words = recursive_split(&(str[len]), c, words_count + 1);
	else
		words = (char **)malloc((words_count + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	if (*str)
	{
		words[words_count] = ft_substr(str, 0, len);
		if (!words[words_count])
			return (NULL);
	}
	else
		words[words_count] = NULL;
	return (words);
}

// #include <string.h>
// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	char	**dst;
// 	int		last_index;

// 	if (argc >= 3)
// 	{
// 		dst = ft_split(argv[1], *argv[2]);
// 		if (dst)
// 		{
// 			printf("ft_split(\"%s\", '%c')\n", argv[1], *argv[2]);
// 			last_index = 0;
// 			for (int i = 0; dst[i] != NULL; i++)
// 			{
// 				printf("%d : \"%s\"\n", i, dst[i]);
// 				free(dst[i]);
// 				last_index = i + 1;
// 			}
// 			printf("%d : \"%s\"\n", last_index, dst[last_index]);
// 			free(dst[last_index]);
// 			free(dst);
// 		}
// 		else
// 		{
// 			printf("the allocation fails\n");
// 		}
// 	}
// }
