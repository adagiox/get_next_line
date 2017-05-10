#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int fd;
	int count = 1;
	int check;
	char *line;

	fd = open("test.txt", O_RDONLY);
	if (fd != -1)
		printf("OPEN SUCCESS!\n");
	else
		printf("OPEN FAILED!\n");

	while ((check = get_next_line(fd, &line)) == 1)
	{
		printf("%i) %s\n", count, line);
		count++;
	}
	if (check == -1)
		printf("ERROR!\n");
	if (check == 0)
		printf("DONE READING!\n");
	close(fd);
	return(0);
}
