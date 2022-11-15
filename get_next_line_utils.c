#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *next_line, char *buff, int len)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (len != BUFFER_SIZE)
		len++;
	if (len == 0)
		return(NULL);
	if (next_line != NULL)
	{
		new = malloc(ft_strlen(next_line) + len + 1);
		while (next_line[i])
		{
			new[i] = next_line[i];
			i++;
		}
	}
	else
		new = malloc(len + 1);
	while (j < len)
	{
		new[i] = buff[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}