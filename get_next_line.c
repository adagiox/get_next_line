#include "get_next_line.h"

int		get_next_line()
{
	int	bytes_read;

	bytes_read = 1;
	return (bytes_read);
}

int		line_size(char *buf)
{
	int line;

	line = 0;
	while (*buf)
	{
		if (*buf == '\n')
			return (line);
		else
			line++;
	}
	return (line);
}