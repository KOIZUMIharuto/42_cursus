/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:55:54 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/05/08 16:21:03 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	**ft_split_2(char const *s, char *delimiter, char **result);
static bool	ft_is_delimiter(char c, char *delimiter);
static char	*strdup_for_split(const char *s1, char *delimiter);
static int	word_flag_checker(char s, char *delimiter, int *word_flag);

char	**ft_split(char const *s, char *delimiter)
{
	int		index;
	int		word_flag;
	size_t	word_count;
	char	**result;

	if (!s)
		return (NULL);
	while (*s && ft_is_delimiter(*s, delimiter))
		s++;
	index = 0;
	word_flag = 1;
	word_count = 0;
	while (s[index])
		if (word_flag_checker((char)(s[(index++)]), delimiter, &word_flag) == 1)
			word_count++;
	result = (char **)malloc ((word_count + 1) * (sizeof(char *)));
	if (!result)
		return (NULL);
	result = ft_split_2(s, delimiter, result);
	return (result);
}

static char	**ft_split_2(char const *s, char *delimiter, char **result)
{
	int		word_flag;
	size_t	word_count;

	word_flag = 1;
	word_count = 0;
	while (*s)
	{
		if (word_flag_checker((char)*s, delimiter, &word_flag) == 1)
		{
			result[word_count] = strdup_for_split(s, delimiter);
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

static bool	ft_is_delimiter(char c, char *delimiter)
{
	if (!delimiter)
		return (false);
	while (*delimiter)
	{
		if (c == *delimiter)
			return (true);
		delimiter++;
	}
	return (false);
}

static char	*strdup_for_split(const char *s1, char *delimiter)
{
	char	*dst;
	size_t	char_count;

	char_count = 0;
	while (s1[char_count] && !ft_is_delimiter(s1[char_count], delimiter))
		char_count++;
	dst = (char *)malloc ((char_count + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	char_count = 0;
	while (*s1 && !ft_is_delimiter(*s1, delimiter))
		dst[char_count++] = *(s1++);
	dst[char_count] = '\0';
	return (dst);
}

static int	word_flag_checker(char s, char *delimiter, int *word_flag)
{
	int	return_flag;
	int	is_in_word;

	is_in_word = 1;
	if (ft_is_delimiter(s, delimiter))
		is_in_word = -1;
	return_flag = 0;
	if (is_in_word == *word_flag)
	{
		return_flag = *word_flag;
		*word_flag *= -1;
	}
	return (return_flag);
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
