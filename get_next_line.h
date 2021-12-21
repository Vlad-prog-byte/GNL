#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//#define  BUFFER_SIZE 42
# include <stdlib.h>
# include <unistd.h>
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char *ft_read(char *str, int *i);
char	*get_next_line(int fd);
#endif