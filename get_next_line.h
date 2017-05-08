#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"

# define BUFF_SIZE 5

int		get_next_line(const int fd, char **line);
char	*get_line(char *buf);
int		contains_newline(char *buf);

#endif
