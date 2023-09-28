#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

int main() {
    int sockfd, newsockfd;

    /*
    * IPv4 adreslerini temsil etmek için kullanılan bir yaıdır.
    * internet tabanlı adresler için kullanılan bir yapı olduğu 
    * belirtir.
    */
    struct sockaddr_in serv_addr, cli_addr;
    int message;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET; // AF_INET (IPv4) veya  AF_INET6 (IPv6)
    serv_addr.sin_port = htons(12346);
    // IP adresi inet_addr("0.0.0.0") = INADDR_ANY ağda bulunan bütün çihazlar
    serv_addr.sin_addr.s_addr = INADDR_ANY;  

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Sunucu soketinin bağlantıları kabul etmeye hazır olduğunu ayarlar.
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Receiver process is waiting for messages...\n");

    // Gelen bağlantı isteklerini kabul etmek için kullanılır.
    socklen_t clilen = sizeof(cli_addr);
    if ((newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen)) < 0) {
        perror("accept");
        exit(1);
    }

    while (read(newsockfd, &message, sizeof(int)) > 0) {
        printf("Received message: %d - Hello\n", message);
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}
