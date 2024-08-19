/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:36:44 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/19 15:42:02 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	char_count;

	if (!s1)
		return (NULL);
	char_count = ft_strlen(s1);
	dst = (char *)malloc ((char_count + 1) * sizeof(char));
	if (dst)
		(void)ft_strlcpy(dst, s1, (char_count + 1) * sizeof(char));
	return (dst);
}

// #include <string.h>
// #include <stdio.h>

// typedef char	*(*t_strdup)(const char *);

// void	test(char **argv, t_strdup strdupFn, char *Fn_name)
// {
// 	char	*dst;

// 	dst = strdupFn(argv[1]);
// 	if (dst)
// 	{
// 		printf("%s : \"%s\" -> \"%s\"\n", Fn_name, argv[1], dst);
// 		free(dst);
// 	}
// 	else
// 	{
// 		printf("the allocation fails\n");
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	if (argc >= 2)
// 	{
// 		test(argv, strdup, "strdup   ");
// 		test(argv, ft_strdup, "ft_strdup");
// 	}
// 	return (0);
// }
