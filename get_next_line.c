#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	int ret;
	char *buf;
	buf = ft_strnew(BUFF_SIZE);

	ret = read(fd, buf, BUFF_SIZE);
	if (ret == -1)
		return(-1);
	if (ret == 0)
		return(0);
	line = &buf;
	return (0);
}
