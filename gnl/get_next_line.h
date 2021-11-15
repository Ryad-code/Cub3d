#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

int		handle_line(char **stack, char **line, char **tmp, int end);
int		handle_stack(char **stack, char **tmp, char *buffer, int rdcpt);
int		manage_output(char **stack, char **line, int rdcpt);
int		extract_line(char **stack, char **line);
int		get_next_line(int fd, char **line);
char	*ft_strdup(char *s1);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, int start, int len);

#endif
