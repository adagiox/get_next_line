#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>


int	main(int argc, char **argv)
{
	int fd;

	fd = open("test.txt", O_RDONLY);

	if (fd != -1)
		printf("OPEN SUCCESS!\n");
	else
		printf("OPEN FAILED!\n");
	return(0);
}
