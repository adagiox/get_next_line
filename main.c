#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int fd;
	int check;
	char **line;

	fd = open("test.txt", O_RDONLY);
	if (fd != -1)
		printf("OPEN SUCCESS!\n");
	else
		printf("OPEN FAILED!\n");

	while ((check = get_next_line(fd, line)) != 0)
	{
		if (check == -1)
		{
			printf("ERROR READING!\n");
			return(-1);
		}
		printf("READ BUFF_SIZE:\n");
		printf("LINE:%c\n", **line);
	}
	printf("Check: %i\n", check);
	printf("DONE READING!\n");
	return(0);
}
