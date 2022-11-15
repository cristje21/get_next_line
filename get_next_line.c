#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	length_of_line(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] && buff[i] != '.')
		i++;
	return (i);
}

char	*move_buff(char *buff, int	line_length)
{
	int	i;

	i = 0;
	line_length++; // 5 buff: four\0
	if (buff[line_length] == '\0')
		buff[0] = '\0';
	while (buff[line_length])
	{
		buff[i] = buff[line_length];
		i++;
		line_length++;
	}
	buff[i] = '\0';
	return (buff);
}

char	*read_some(char *buff, char *next_line, int fd)
{
	int	bytes_read;
	int	line_length;

	line_length = BUFFER_SIZE;
	while (line_length == BUFFER_SIZE)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1 || bytes_read == 0)
			return (NULL);
		buff[bytes_read] = '\0';
		line_length = length_of_line(buff);
		next_line = ft_strjoin(next_line, buff, line_length);
		if (next_line == NULL)
			return (NULL);
	}
	buff = move_buff(buff, line_length);
	return (next_line);
}

char *get_next_line(int fd)
{
	static char	*buff = NULL;
	char		*next_line = NULL;
	int			line_length;

	line_length = BUFFER_SIZE;
	if (buff == NULL)
		buff = malloc(BUFFER_SIZE + 1);
	else
	{
		line_length = length_of_line(buff);
		next_line = ft_strjoin(next_line, buff, line_length);
		if (next_line == NULL)
			return (NULL);
		if (line_length < ft_strlen(buff))
		{
			buff = move_buff(buff, line_length);
			return (next_line);
		}
	}
	if (buff == NULL)
		return (NULL);
	next_line = read_some(buff, next_line, fd);
	if (next_line == NULL)
		return (NULL);
	return (next_line);
}
