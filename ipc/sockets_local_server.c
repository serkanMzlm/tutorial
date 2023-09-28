#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

/*
* un.h kütüphanesi UNIX soketlerinin oluşturmak, bind,
* listen, accept, read, write ve close işlemlerini içerir.
*/
#include <sys/un.h>
#include <unistd.h>


#define SOCKET_NAME "/tmp/addNumberSocket"
#define BUFFER_SIZE 128

#define COLOR_BLK "\x1b[30m"
#define COLOR_RED "\x1b[31m"
#define COLOR_GRN "\x1b[32m"
#define COLOR_YLW "\x1b[33m"
#define COLOR_BLE "\x1b[34m"
#define COLOR_MGT "\x1b[35m"
#define COLOR_CYN "\x1b[36m"
#define COLOR_WHT "\x1b[37m"
#define COLOR_RST "\x1b[0m"

int main(){
    struct sockaddr_un name;
    int ret;
    int connection_socket;
    int data_socket;
    int result;
    int data;
    char buffer[BUFFER_SIZE];
    
    unlink(SOCKET_NAME); // Belirtilen dosyanın silinmesini sağlar.
    connection_socket = socket(AF_UNIX, SOCK_STREAM, 0);

    if (connection_socket == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&name, 0, sizeof(struct sockaddr_un));

    name.sun_family = AF_UNIX;
    strncpy(name.sun_path, SOCKET_NAME, sizeof(name.sun_path) - 1);

    ret = bind(connection_socket, (const struct sockaddr *) &name,
            sizeof(struct sockaddr_un));

    if (ret == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    ret = listen(connection_socket, 20);
    if (ret == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    for (;;) {
        data_socket = accept(connection_socket, NULL, NULL);

        if (data_socket == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        
        printf(COLOR_GRN"Connection accepted from client\n");

        result = 0;
        for(;;) {

            memset(buffer, 0, BUFFER_SIZE);

            printf(COLOR_YLW"Waiting...\n");
            ret = read(data_socket, buffer, BUFFER_SIZE);

            if (ret == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            }

            memcpy(&data, buffer, sizeof(int));
            if(data == 0) break;

            printf(COLOR_RST"Client Data: "COLOR_GRN"%d\n"COLOR_RST, data);
            result += data;
        }

        memset(buffer, 0, BUFFER_SIZE);
        sprintf(buffer, "Result = %d", result);

        printf(COLOR_RST"sending final result back to client\n");
        ret = write(data_socket, buffer, BUFFER_SIZE);
        if (ret == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        close(data_socket);
    }

    close(connection_socket);
    printf(COLOR_GRN"connection closed..\n");

    unlink(SOCKET_NAME);
    exit(EXIT_SUCCESS);
    return 0;
}