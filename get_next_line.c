#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char buf[BUFF_SIZE];
	char *temp;
	int ret;
	int nl;

	if (contains_newline(buf) == 1)
	{
		temp = get_line(buf);
		*line = temp;
		return(1);
	}

	temp = ft_strnew(BUFF_SIZE + 1);
	ret = read(fd, buf, BUFF_SIZE);
	while ((nl = contains_newline(buf)) == 0)
	{
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

char	*get_line(char *buf)
{
	// RETURNS EVERYTHING UP TO THE NEWLINE
	// AND REMOVES THE LINE FROM BUF
	int size;
	char *line;

	size = 0;
	while (buf[size] != '\n')
		size++;
	line = ft_strsub(buf, 0, size);
	buf = ft_strncpy(buf, &buf[size + 1], BUFF_SIZE - (size + 1));
	return(line);
}

int		contains_newline(char *buf)
{
	// IF BUF CONSTAINS A NEW LINE RETURN 1
	char *nl;
	nl = ft_strchr(buf, '\n');
	if (*nl == '\n')
		return(1);
	return(0);
}
