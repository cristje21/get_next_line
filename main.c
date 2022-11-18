#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("file.txt", O_RDONLY);
	while (i < 3)
	{
		printf("%s", get_next_line(fd));
		printf("\n------------------------\n");
		i++;
	}
	close(fd);
	return (0);
}