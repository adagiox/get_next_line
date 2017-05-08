#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char buf[BUFF_SIZE + 1];
	char *temp;
	int ret;

	if (contains_newline(buf) == 1)
	{
		temp = get_line(buf);
		line = &temp;
		printf("line return: %s\n", *line);
		trim_buf(buf);
		return(1);
	}
	temp = ft_strnew(BUFF_SIZE + 1);
	temp = ft_strjoin(buf, temp);
	ft_strclr(buf);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		temp = ft_strjoin(temp, buf);
		if ((contains_newline(buf)) == 1)
		{
			temp = get_line(temp);
			line = &temp;
			printf("line return: %s\n", *line);
			trim_buf(buf);
			return (1);
		}
	}
	if (ret == -1)
		return(-1);
	if (ret == 0)
		return(0);
	return (1);
}

void	trim_buf(char *buf)
{
	int size;

	size = 0;
	while (buf[size] != '\n')
		size++;
	buf = ft_strncpy(buf, &buf[size + 1], BUFF_SIZE);
}

char	*get_line(char *buf)
{
	// RETURNS EVERYTHING UP TO THE NEWLINE
	int size;
	char *line;

	size = 0;
	while (buf[size] != '\n')
		size++;
	line = ft_strsub(buf, 0, size);
	return(line);
}

int		contains_newline(char *buf)
{
	// IF BUF CONSTAINS A NEW LINE RETURN 1
	char *nl;
	nl = ft_strchr(buf, '\n');
	if (nl == NULL)
		return(0);
	if (*nl == '\n')
		return(1);
	return(0);
}
