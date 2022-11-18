/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-sch <cvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/18 17:01:16 by cvan-sch      #+#    #+#                 */
/*   Updated: 2022/11/18 17:01:39 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

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
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*new_stash(char *stash, int line_length, int check)
{
	int		size;
	char	*new_stash;
	int		i;

	i = 0;
	size = ft_strlen(stash) - line_length;
	if (size <= 0 && check)
		return (free(stash), NULL);
	else if (size <= 0)
		return (NULL);
	new_stash = malloc(size + 1);
	if (new_stash == NULL || stash == NULL)
		return (NULL);
	while (stash[line_length])
	{
		new_stash[i] = stash[line_length];
		i++;
		line_length++;
	}
	new_stash[i] = '\0';
	if (check)
		free (stash);
	return (new_stash);
}

char	*ft_strjoin(char *next_line, char *stash, int line_length)
{
	char	*new;
	int		i;
	int		j;

	j = -1;
	i = 0;
	if (line_length > ft_strlen(stash))
		line_length -= 1;
	if (next_line != NULL)
		new = malloc(ft_strlen(next_line) + line_length + 1);
	else
		new = malloc(line_length + 1);
	if (new == NULL)
		return (free(stash), NULL);
	if (next_line)
		while (next_line[++j])
			new[j] = next_line[j];
	else
		j = 0;
	while (i < line_length)
	{
		new[j++] = *(stash + i);
		i++;
	}
	new[j] = '\0';
	return (free(next_line), new);
}

char	*get_N_line(char *next_line, char **stash, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	int		line_length;

	bytes_read = BUFFER_SIZE;
	while (bytes_read == BUFFER_SIZE)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(next_line), NULL);
		buffer[bytes_read] = '\0';
		line_length = length_of_line(buffer);
		next_line = ft_strjoin(next_line, buffer, line_length);
		if (line_length >= bytes_read)
		{
			if (line_length == bytes_read)
				return (next_line);
			continue ;
		}
		*stash = new_stash(buffer, line_length, 0);
		return (next_line);
	}
	return (next_line);
}
