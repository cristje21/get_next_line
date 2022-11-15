#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
	int	fd;

	fd = open("file.txt", O_RDWR);
	// printf("%d\n", length_of_line("."));
	// printf("%s\n", ft_strjoin(NULL , "is lekker", 6));
	for (int i = 0; i < 6; i++)
	{
		printf("%s", get_next_line(fd));
		printf("\n------------------------\n");
	}
	close(fd);
	return (0);
}