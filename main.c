#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int fd1;
	int fd2;
	int fd3;
	int check1;
	int check2;
	int check3;
	char *line;

	fd1 = open("Moby Dick 1", O_RDONLY);
	fd2 = open("Moby Dick 2", O_RDONLY);
	fd3 = open("Moby Dick 3", O_RDONLY);
	if (fd1 != -1)
		printf("OPEN 1 SUCCESS!\n");
	else
		printf("OPEN 1 FAILED!\n");

	if (fd2 != -1)
		printf("OPEN 2 SUCCESS!\n");
	else
		printf("OPEN 2 FAILED!\n");
	if (fd3 != -1)
		printf("OPEN 3 SUCCESS!\n");
	else
		printf("OPEN 3 FAILED!\n");

	// READ FD1
	if(check1 = get_next_line(fd1, &line)) == 1
	{
		printf("%s\n", line);
	}
	if (check1 == -1)
		printf("ERROR 1!\n");
	if (check1 == 0)
		printf("DONE READING 1!\n");

	// READ FD2
	if(check2 = get_next_line(fd2, &line)) == 1
	{
		printf("%s\n", line);
	}
	if (check2 == -1)
		printf("ERROR 2!\n");
	if (check2 == 0)
		printf("DONE READING 2!\n");


	close(fd1);
	close(fd2);
	close(fd3);
	return(0);
}
