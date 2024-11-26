#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void) {
	int fd = open("hardtest_cases.txt", O_RDONLY);

	char *line = get_next_line(fd);
	while (line) {
		printf("->%s<-", line);
		free(line);
		line = get_next_line(fd);
	}

	close(fd);
	return 0;
}
