/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:48:20 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/19 15:35:49 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write (fd, s, ft_strlen(s));
}

// #include <stdio.h>
// #include<sys/types.h>
// #include<sys/stat.h>
// #include<fcntl.h>

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
// 		ft_putstr_fd(argv[1], fd);
// 		close(fd);
// 		printf("done\n");
// 	}
// 	return (0);
// }
