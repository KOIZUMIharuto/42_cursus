/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:49:36 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/19 15:35:49 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_isprint(int c)
{
	return (' ' <= c && c <= '~');
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	if(argc >= 2)
// 	{
// 		printf("isprint    : %c -> %d\n", argv[1][0], isprint(argv[1][0]));
// 		printf("ft_isprint : %c -> %d\n", argv[1][0], ft_isprint(argv[1][0]));
// 		printf("isprint    : %c -> %d\n", '\t', isprint('\t'));
// 		printf("ft_isprint : %c -> %d\n", '\t', ft_isprint('\t'));
// 	}
// 	return (0);
// }
