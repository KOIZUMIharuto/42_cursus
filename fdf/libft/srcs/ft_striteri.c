/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:26:30 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/19 15:35:49 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	index;

	if (s && f)
	{
		index = -1;
		while (s[++index])
			f(index, &(s[index]));
	}
}

// #include <string.h>
// #include <stdio.h>

// void	test(unsigned int index, char *c)
// {
// 	if (index % 2 == 0)
// 		*c += 1;
// 	else
// 		*c -= 1;
// }

// int	main(int argc, char **argv)
// {
// 	if (argc >= 2)
// 	{
// 		printf("\"%s\" -> ", argv[1]);
// 		ft_striteri(argv[1], test);
// 		printf("\"%s\"\n", argv[1]);
// 	}
// 	return (0);
// }
