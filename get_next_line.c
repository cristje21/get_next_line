#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char*	get_next_line(int fd)
{
	static char	*stash;
	int			line_length;
	char		*next_line;

	next_line = NULL;
	stash = strdup("hein");
	if (stash)
	{
		line_length = length_of_line(stash);
		printf("%d\n", line_length);
		next_line = ft_strjoin(next_line, stash, line_length);
		if ((ft_strlen(stash) - line_length) <= 0)
		{
			if (ft_strlen(stash) - line_length == 0)
				return (free(stash), next_line);
			free(stash);
		}
		else if ((ft_strlen(stash) - line_length ) > 0)
			stash = new_stash(stash, line_length);
	}
	line_length = 0;
	fd = line_length;
	return ("baardaapje");
}
