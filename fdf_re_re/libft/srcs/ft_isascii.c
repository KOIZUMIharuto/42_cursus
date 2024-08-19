/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:44:19 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/19 15:42:02 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	if(argc >= 2)
// 	{
// 		printf("isascii    : %c -> %d\n", argv[1][0], isascii(argv[1][0]));
// 		printf("ft_isascii : %c -> %d\n", argv[1][0], ft_isascii(argv[1][0]));
// 	}
// 	return (0);
// }
