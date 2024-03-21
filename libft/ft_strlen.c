/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:11:33 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/19 16:25:04 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

// #include <string.h>
// #include <stdlib.h>
// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	if (argc >= 2)
// 	{
// 		printf("strlen    -> \"%s\" [%lu]\n", argv[1], strlen(argv[1]));
// 		printf("ft_strlen -> \"%s\" [%zu]\n", argv[1], ft_strlen(argv[1]));
// 	}
// 	return (0);
// }
