#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME "15011098_c"

int main() {

	char buf[100];
	int num, fd;

	//making a FD for FIFO
	if(mknod(FIFO_NAME, S_IFIFO | 0666, 0) == -1) {
		perror("mkknod error");
	}

	//waiting for a reader
	//open the FD, when the reader opens the FD
	
	printf("WRITER : waiting for a reader.\n");
	fd = open(FIFO_NAME, O_WRONLY);

	printf("WRITER : the reader ready.\n");
	printf("WRITER : your input: ");

	//send the user input data to the reader via fifo
	
	while (fgets(buf, sizeof(buf), stdin), !feof(stdin)) {
		if((num = write(fd, buf, strlen(buf))) == -1) {
			perror("writer error");
		} else {
			printf("WRITER : wrotte %d bytes\n", num);
		}
	}

	return 0;
}
