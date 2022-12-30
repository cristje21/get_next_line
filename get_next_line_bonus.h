/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-sch <cvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/20 19:34:15 by cvan-sch      #+#    #+#                 */
/*   Updated: 2022/11/24 17:34:51 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		str_len_of_line(char *s, int check);
char	*new_stash(char *stash, int line_length, int check);
char	*gnl_join(char *next_line, char *stash, int line_length);
char	*get_n_line(char *next_line, char **stash, int fd);
int		use_stash(char **stash, char **next_line);
void	re_assign(char **stash, char **next_line, int o);

#endif