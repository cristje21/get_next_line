#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char*	get_next_line(int fd)
{
	static char	*stash = NULL;
	int			line_length;
	char		*next_line;
	int			len;

	next_line = NULL;
	line_length = 0;
	len = 0;
	if (stash)
	{
		len = ft_strlen(stash);
		line_length = length_of_line(stash);
		next_line = ft_strjoin(next_line, stash, line_length);
		if (line_length >= len)
		{
			free(stash);
			stash = NULL;
			if (line_length == len)
				return(next_line);
		}
		stash = new_stash(stash, line_length);
		if (line_length < len)
			return (next_line);
	}
	next_line = get_line(next_line, &stash, fd);
	return (next_line);
}
