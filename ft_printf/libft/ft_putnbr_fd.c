/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:53:30 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/02/14 12:31:42 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putui_fd(unsigned int n, int fd)
{
	char	output;

	if (n >= 10)
	{
		ft_putui_fd(n / 10, fd);
	}
	output = n % 10 + '0';
	ft_putchar_fd(output, fd);
}

unsigned int	abs_ui(int n)
{
	if (n < 0)
		return ((unsigned int)(-n));
	return ((unsigned int)n);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	ft_putui_fd(abs_ui(n), fd);
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
