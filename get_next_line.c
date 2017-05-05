#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	int ret;
	char *buf;
	static char *temp;
	int nl;
	int count;

	count = 1;
	buf = ft_strnew(BUFF_SIZE + 1);
	temp = ft_strnew(BUFF_SIZE + 1);
	ret = read(fd, temp, BUFF_SIZE);
	if (ret == -1)
		return(-1);
	if (ret == 0)
		return(0);
	while ((nl = contains_newline(temp)) == 0)
	{
		count++;
		temp = ft_strcpy(temp, buf);
		buf = ft_strnew((BUFF_SIZE * count) + 1);
		ret = read(fd, buf, (BUFF_SIZE * count));
		if (ret < 1)
			break ;
	}
	if (ret == -1)
		return(-1);
	if (ret == 0)
		return(0);
	printf("BUF: %s\n", buf);
	*line = buf;
	return (1);
}



int	contains_newline(char *buf)
{
	char *nl;
	nl = ft_strchr(buf, '\n');
	if (*nl != '\n')
		return(0);
	return(1);
}
