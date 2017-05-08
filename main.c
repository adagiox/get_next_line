#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int fd;
	int check;
	char **line;

	line = (char **)malloc(sizeof(char *));
	fd = open("test.txt", O_RDONLY);
	if (fd != -1)
		printf("OPEN SUCCESS!\n");
	else
		printf("OPEN FAILED!\n");

	while ((check = get_next_line(fd, line)) == 1)
	{
		if (line == NULL)
			printf("NULL\n");
		printf("NOT NULL\n");
		printf("READ ONE LINE:\n%s\n", *line);
		ft_strclr(*line);
	}
	printf("DONE READING!\n");
	close(fd);
	return(0);
}
