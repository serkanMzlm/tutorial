#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO_NAME "/tmp/ex_pipe"

int main() {
    int fd;
    int message;

    mkfifo(FIFO_NAME, 0666);
    
    if ((fd = open(FIFO_NAME, O_RDONLY)) == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    printf("Receiver process is waiting for messages...\n");

    while (read(fd, &message, sizeof(int)) > 0) {
        printf("Received message: %d - Hello\n", message);
    }

    close(fd);
    return 0;
}