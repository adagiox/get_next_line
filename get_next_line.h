#include <stdlib.h>

// List for holding lines

typedef struct		s_line
{
	unsigned char	*content;
	unsigned int	content_size;
	struct s_line	*next;
}					t_line;