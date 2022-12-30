/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-sch <cvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/20 19:34:22 by cvan-sch      #+#    #+#                 */
/*   Updated: 2022/12/06 11:08:02 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <limits.h>

void	re_assign(char **stash, char **next_line, int o)
{
	if (o == 0 || o == 2)
	{
		if (*stash)
			free(*stash);
		*stash = NULL;
	}
	if (o == 1 || o == 2)
	{
		if (*next_line)
			free(*next_line);
		*next_line = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	next_line = NULL;
	if (use_stash(stash + fd, &next_line))
	{
		next_line = get_n_line(next_line, stash + fd, fd);
		if (!next_line)
			return (re_assign(stash + fd, NULL, 0), NULL);
		if (*next_line == '\0')
			return (re_assign(NULL, &next_line, 1), NULL);
	}
	return (next_line);
}
