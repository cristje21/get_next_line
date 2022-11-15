#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

char    *get_next_line(int fd);
int	    ft_strlen(char *s);
char	*ft_strjoin(char *next_line, char *buffer, int len);
int	    length_of_line(char *buff);

#endif