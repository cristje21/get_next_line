#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include <string.h>

int	length_of_line(char *stash)
{
	int	i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	return (i + 1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*new_stash(char *stash, int line_length)
{
	int		size;
	char	*new_stash;

	size = ft_strlen(stash) - line_length;
	new_stash = malloc(size + 1);
	if (new_stash == NULL)
		return (NULL);
	while (*(stash + line_length))
	{
		*new_stash = *(stash + line_length);
		new_stash++;
		line_length++;
	}
	*new_stash = '\0';
	return (free(stash), new_stash);
}

char	*ft_strjoin(char *next_line, char *stash, int line_length)
{
	char	*new;
	int		i;

	i = 0;
	if (line_length > ft_strlen(stash))
		line_length--;
	if (next_line != NULL)
		new = malloc(line_length + 1);
	else
		new = malloc(ft_strlen(next_line) + line_length + 1);
	if (new == NULL)
		return (free(stash), NULL);
	if (next_line)
		while (next_line)
			*new++ = *next_line++; 
	while (i < line_length)
	{
		*new++ = *(stash + i);
		i++;
	}
	*new = '\0';
	return (free(next_line), new);
}
