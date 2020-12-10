#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define FIFO_NAME "15011098_c"

int main() {

	char buf[100];
	int num, fd;

	//make a FD, which is the same one the writer uses, for fifo
	if (mknod(FIFO_NAME, S_IFIFO | 0666, 0) == -1) {
		perror("mknod error");
	}

	//waiting for the writer
	//open the fd, when the writer opens the fd
	
	printf("READER : waiting for a writer.\n");
	fd = open(FIFO_NAME, O_RDONLY);

	printf("READER : the writer ready.\n");

	do {
		if ((num = read(fd, buf, 100)) == -1) {
			perror("read error");
		} else {
			buf[num] = '\0';
			printf("%s+1 = %d\n", buf, atoi(buf)+1);
		}
	} while (num > 0);

	return 0;
}
