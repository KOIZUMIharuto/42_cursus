/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:53:30 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/03/31 11:51:01 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*str;

	str = ft_itoa(n);
	if (str)
	{
		ft_putstr_fd(str, fd);
		free(str);
	}
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>

// int	main(int argc, char **argv)
// {
// 	int fd;
// 	if (argc >= 3)
// 	{
// 		fd = open(argv[2], O_WRONLY);
// 		if (fd == -1)
// 		{
// 			printf ("open error\n");
// 			return (0);
// 		}
// 		ft_putnbr_fd((atoi)(argv[1]), fd);
// 		close(fd);
// 		printf("done (%d)\n", (atoi)(argv[1]));
// 	}
// 	return (0);
// }
