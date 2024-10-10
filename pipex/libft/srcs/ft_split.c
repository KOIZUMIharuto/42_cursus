/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:55:54 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/10/10 14:53:49 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	**recursive_split(char *str, char *del, int words_count);

char	**ft_split(char const *str, char *del)
{
	char	**words;

	if (!str)
		return (NULL);
	words = recursive_split((char *)str, del, 0);
	return (words);
}

static char	**recursive_split(char *str, char *del, int words_count)
{
	int		len;
	char	**words;

	while (*str && ft_strchr(del, *str) != NULL)
		str++;
	len = 0;
	while (*str && str[len] && ft_strchr(del, str[len]) == NULL)
		len++;
	if (*str)
		words = recursive_split(&(str[len]), del, words_count + 1);
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
