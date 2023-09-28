#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <errno.h>

#define MAX_MSG_SIZE        256
#define MSG_BUFFER_SIZE     (MAX_MSG_SIZE + 10)


int main(int argc, char **argv){

    char buffer[MSG_BUFFER_SIZE];
    int recvr_msgq_fd = 0;

    if(argc <= 1){ return 0;  }

    memset(buffer, 0, MSG_BUFFER_SIZE);
    printf("Enter msg to be sent  %s:", argv[1]);
    scanf("%s", buffer);

    if ((recvr_msgq_fd  = mq_open (argv[1], O_WRONLY | O_CREAT, 0, 0)) == -1) {
        perror("mq_open");
        exit (1);
    }

    if (mq_send (recvr_msgq_fd, buffer, strlen (buffer) + 1, 0) == -1) {
        perror("mq_send");
        exit (1);
    }

    mq_close(recvr_msgq_fd);
    return 0;
}
