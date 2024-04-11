
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include "../get_next_line_bonus.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	char	*line1;
	char	*line2;

	fd1 = open("../get_next_line.h", O_RDONLY);
	fd2 = open("../get_next_line_bonus.h", O_RDONLY);
	// fd1 = open("file1.txt", O_RDONLY);
	// fd2 = open("file2.txt", O_RDONLY);
	fd3 = open("file3.txt", O_WRONLY);
	fd4 = open("file4.txt", O_WRONLY);

	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);

	while (line1 || line2)
	{
		if (line1)
		{
			write(fd3, line1, strlen(line1));
			line1 = get_next_line(fd1);
		}
		if (line2)
		{
			write(fd4, line2, strlen(line2));
			line2 = get_next_line(fd2);
		}
	}

	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);

	return (0);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q gnl_bonus");
// }

// cc -Wall -Wextra -Werror ../get_next_line_bonus.c ../get_next_line_utils_bonus.c main_bonus.c -o gnl_bonus -D BUFFER_SIZE=42
