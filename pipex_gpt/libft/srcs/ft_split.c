/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:55:54 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/31 11:51:01 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*strdup_for_split(const char *s1, char c)
{
	char	*dst;
	size_t	char_count;

	char_count = 0;
	while (s1[char_count] && s1[char_count] != c)
		char_count++;
	dst = (char *)malloc ((char_count + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	char_count = 0;
	while (*s1 && *s1 != c)
		dst[char_count++] = *(s1++);
	dst[char_count] = '\0';
	return (dst);
}

int	word_flag_checker(char s, char c, int *word_flag)
{
	int	return_flag;
	int	is_in_word;

	is_in_word = 1;
	if (s == c)
		is_in_word = -1;
	return_flag = 0;
	if (is_in_word == *word_flag)
	{
		return_flag = *word_flag;
		*word_flag *= -1;
	}
	return (return_flag);
}

char	**ft_split_2(char const *s, char c, char **result)
{
	int		word_flag;
	size_t	word_count;

	word_flag = 1;
	word_count = 0;
	while (*s)
	{
		if (word_flag_checker((char)*s, c, &word_flag) == 1)
		{
			result[word_count] = strdup_for_split(s, c);
			if (!result[word_count++])
			{
				while (--word_count > 0)
					free(result[word_count]);
				free(result);
				return (NULL);
			}
		}
		s++;
	}
	result[word_count] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	int		word_flag;
	size_t	word_count;
	char	**result;

	if (!s)
		return (NULL);
	while (*s && *s == c)
		s++;
	index = 0;
	word_flag = 1;
	word_count = 0;
	while (s[index])
		if (word_flag_checker((char)(s[(index++)]), c, &word_flag) == 1)
			word_count++;
	result = (char **)malloc ((word_count + 1) * (sizeof(char *)));
	if (!result)
		return (NULL);
	result = ft_split_2(s, c, result);
	return (result);
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
