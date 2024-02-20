/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:33:13 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/02/14 11:49:31 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	if(argc >= 2)
// 	{
// 		printf("isalnum    : %c -> %d\n", argv[1][0], isalnum(argv[1][0]));
// 		printf("ft_isalnum : %c -> %d\n", argv[1][0], ft_isalnum(argv[1][0]));
// 	}
// 	return (0);
// }
