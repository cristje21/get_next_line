#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

char	*get_next_line(int fd);
int		length_of_line(char *stash);
int		ft_strlen(char *s);
char	*new_stash(char *stash, int line_length);
char	*ft_strjoin(char *next_line, char *stash, int line_length);

#endif