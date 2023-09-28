#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    int count = 1;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(12346);
    
    /* INADDR_ANY Bütün makinelerden gelen verileri kabul
    * eder. INADDR_LOOPBACK Localhost (127.0.0.1)*/
    serv_addr.sin_addr.s_addr = INADDR_ANY; //inet_addr("server_ip_addr"); //INADDR_ANY; // inet_addr("server_ip_addr")

    // Sunucuya bağlantı göndermek için kullanılır.
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    while (count <= 30) {
        printf("%d - Hello\n", count);
        write(sockfd, &count, sizeof(int));
        count++;
        sleep(1);
    }

    close(sockfd);
    return 0;
}

