/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:32:51 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/07/09 14:45:10 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	index;
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dst = (char *)malloc ((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	index = ft_strlcpy(dst, s1, (len + 1) * sizeof(char));
	index += ft_strlcpy(&dst[index], s2, (len + 1 - index) * sizeof(char));
	dst[index] = '\0';
	return (dst);
}

// #include <string.h>
// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	char	*dst;
// 	if (argc >= 3)
// 	{
// 		dst = ft_strjoin(NULL, NULL);
// 		if (dst)
// 		{
// 			printf("\"%s\" + \"%s\" = \"%s\"\n", argv[1], argv[2], dst);
// 			free(dst);
// 		}
// 		else
// 		{
// 			printf("the allocation fails\n");
// 		}
// 	}
// 	return (0);
// }
