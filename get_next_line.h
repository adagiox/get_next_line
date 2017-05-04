#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"

// List for holding lines

typedef struct		s_line
{
	unsigned char	*content;
	unsigned int	content_size;
	struct s_line	*next;
}					t_line;

# define BUFF_SIZE 10

int	get_next_line(const int fd, char **line);

#endif
