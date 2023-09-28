#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCKET_NAME "/tmp/addNumberSocket"
#define BUFFER_SIZE 128
#define MAX_CLIENT 10 

#define COLOR_BLK "\x1b[30m"
#define COLOR_RED "\x1b[31m"
#define COLOR_GRN "\x1b[32m"
#define COLOR_YLW "\x1b[33m"
#define COLOR_BLE "\x1b[34m"
#define COLOR_MGT "\x1b[35m"
#define COLOR_CYN "\x1b[36m"
#define COLOR_WHT "\x1b[37m"
#define COLOR_RST "\x1b[0m"

int monitored_fd_set[MAX_CLIENT];
int client_result[MAX_CLIENT] = {0};
fd_set readfds;

static void intitiaze_monitor_fd_set(){
    for(int i = 0; i < MAX_CLIENT; i++)
        monitored_fd_set[i] = -1;
}

static void add_to_monitored_fd_set(int skt_fd){
    for(int i = 0; i < MAX_CLIENT; i++){
        if(monitored_fd_set[i] != -1)
            continue;
        monitored_fd_set[i] = skt_fd;
        break;
    }
}

static void remove_from_monitored_fd_set(int skt_fd){
    for(int i = 0; i < MAX_CLIENT; i++){
        if(monitored_fd_set[i] != skt_fd)
            continue;
        monitored_fd_set[i] = -1;
        break;
    }
}

static void refresh_fd_set(fd_set *fd_set_ptr){
    FD_ZERO(fd_set_ptr);
    for(int i = 0; i < MAX_CLIENT; i++){
        if(monitored_fd_set[i] != -1){
            FD_SET(monitored_fd_set[i], fd_set_ptr);
        }
    }
}

static int get_max_fd(){
    int max = -1;
    for(int i = 0; i < MAX_CLIENT; i++){
        if(monitored_fd_set[i] > max)
            max = monitored_fd_set[i];
    }
    return max;
}

int main(int argc, char *argv[]){
    struct sockaddr_un name;
    int ret;
    int connection_socket;
    int data_socket;
    int result;
    int data;
    char buffer[BUFFER_SIZE];
    int comm_socket_fd, i;
    intitiaze_monitor_fd_set();
    add_to_monitored_fd_set(0);
    unlink(SOCKET_NAME);
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

    add_to_monitored_fd_set(connection_socket);
    for (;;) {
        refresh_fd_set(&readfds); 
        select(get_max_fd() + 1, &readfds, NULL, NULL, NULL);

        if(FD_ISSET(connection_socket, &readfds)){
            printf(COLOR_GRN"New connection\n"COLOR_RST);
            data_socket = accept(connection_socket, NULL, NULL);

            if (data_socket == -1) {
                perror("accept");
                exit(EXIT_FAILURE);
            }
            add_to_monitored_fd_set(data_socket);
        }else if(FD_ISSET(0, &readfds)){
            memset(buffer, 0, BUFFER_SIZE);
            ret = read(0, buffer, BUFFER_SIZE);
            printf("Input read from console : %s\n", buffer);
        }else{
            i = 0, comm_socket_fd = -1;
            for(; i < MAX_CLIENT; i++){

                if(FD_ISSET(monitored_fd_set[i], &readfds)){
                    comm_socket_fd = monitored_fd_set[i];

                    memset(buffer, 0, BUFFER_SIZE);
                    printf(COLOR_YLW"Waiting client\n"COLOR_RST);
                    ret = read(comm_socket_fd, buffer, BUFFER_SIZE);

                    if (ret == -1) {
                        perror("read");
                        exit(EXIT_FAILURE);
                    }

                    memcpy(&data, buffer, sizeof(int));
                    printf(COLOR_RST"%d. Client Data: "COLOR_GRN"%d\n"COLOR_RST,i - 1, data);

                    if(data == 0) {
                        memset(buffer, 0, BUFFER_SIZE);
                        sprintf(buffer, "Result = %d", client_result[i]);

                        printf(COLOR_RED"Send the final result back to the %d. customer\n"COLOR_RST, i - 1);
                        ret = write(comm_socket_fd, buffer, BUFFER_SIZE);
                        if (ret == -1) {
                            perror("write");
                            exit(EXIT_FAILURE);
                        }

                        close(comm_socket_fd);
                        client_result[i] = 0; 
                        remove_from_monitored_fd_set(comm_socket_fd);
                        continue; 
                    }
                    client_result[i] += data;
                }
            }
        }
    } 

    close(connection_socket);
    remove_from_monitored_fd_set(connection_socket);
    printf("connection closed..\n");

    unlink(SOCKET_NAME);
    exit(EXIT_SUCCESS);
}