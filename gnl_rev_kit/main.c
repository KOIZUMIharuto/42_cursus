
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include "../get_next_line.h"

int	main(void)
{
	int		fd1;
	char	*line1;

	fd1 = open("../get_next_line.h", O_RDONLY);
	// fd1 = open("file1.txt", O_RDONLY);

	line1 = get_next_line(fd1);

	while (line1)
	{
		printf("%s", line1);
		line1 = get_next_line(fd1);
	}

	close(fd1);

	return (0);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q gnl");
// }

// cc -Wall -Wextra -Werror ../get_next_line.c ../get_next_line_utils.c main.c -o gnl -D BUFFER_SIZE=42