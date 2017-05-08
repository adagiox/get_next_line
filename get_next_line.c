#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char buf[BUFF_SIZE];
	char *temp;
	int ret;
	int nl;
	int count;

	if (nl = contains_newline(buf) == 1)
	{
		temp = get_line(buf);
	}

	count = 1;
	buf = ft_strnew(BUFF_SIZE + 1);
	temp = ft_strnew(BUFF_SIZE + 1);
	ret = read(fd, buf, BUFF_SIZE);
	while ((nl = contains_newline(buf)) == 0)
	{
		count++;
		temp = ft_strcpy(buf, temp);
	}
	if (ret == -1)
		return(-1);
	if (ret == 0)
		return(0);
	printf("BUF: %s\n", temp);
	*line = temp;
	return (1);
}

int		buf_empty(static char *buf)
{
	// IF BUF IS EMPTY RETURN 1
	if (*buf == '\0')
		return(1)
	return(-1);
}

char	*get_line(static char *buf)
{
	// RETURNS EVERYTHING UP TO THE NEWLINE
	int size;
	char *line;

	size = 0;
	while (buf[size] != '\n')
		size++;
	line = ft_strnew(size);
	line = ft_strncpy(line, buf, size);
	return(line);
}

int		contains_newline(char *buf)
{
	// IF BUF CONSTAINS A NEW LINE RETURN 1
	char *nl;
	nl = ft_strchr(buf, '\n');
	if (*nl != '\n')
		return(0);
	return(1);
}
