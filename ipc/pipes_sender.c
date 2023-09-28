#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO_NAME "/tmp/ex_pipe"

int main() {
    int fd;
    int count = 1;

    mkfifo(FIFO_NAME, 0666);
    
    if ((fd = open(FIFO_NAME, O_WRONLY)) == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    while (count <= 30) {
        printf("%d - Hello\n", count);
        if (write(fd, &count, sizeof(int)) == -1) {
            perror("write");
            close(fd);
            exit(EXIT_FAILURE);
        }
        count++;
        sleep(1);
    }

    close(fd);
    return 0;
}