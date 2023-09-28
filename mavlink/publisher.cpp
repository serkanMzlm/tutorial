#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h>

#define PORT 8080

int server_socket;
int client_socket;

void signal_handler(int signal) {
    if (signal == SIGINT) {
         printf("Soket Kapatıldı\n");
        close(client_socket);
        close(server_socket);
        exit(EXIT_SUCCESS);
    }
}

int main() {
    struct sockaddr_in server_address, client_address;
    int client_address_length = sizeof(client_address);

    char message[] = "hello world";

    // Sunucu soketini oluşturma
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Sunucu soketi oluşturulamadı");
        exit(EXIT_FAILURE);
    }

    // Sunucu adresini yapılandırma
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Sunucu soketini belirli bir adrese ve porta bağlama
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Sunucu soketi bağlanamadı");
        exit(EXIT_FAILURE);
    }

    // [CTRL+C](https://www.google.com/search?q=CTRL%2BC) tuş kombinasyonunu dinleme
    signal(SIGINT, signal_handler);

    // İstemci bağlantılarını dinleme
    if (listen(server_socket, 3) < 0) {
        perror("İstemci bağlantıları dinlenemedi");
        exit(EXIT_FAILURE);
    }

    // Sürekli olarak istemcilerden gelen bağlantıları kabul etme
    while (1) {
        // İstemciden gelen bağlantıyı kabul etme
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&client_address_length);
        if (client_socket < 0) {
            perror("İstemci bağlantısı kabul edilemedi");
            exit(EXIT_FAILURE);
        }

        // İstemciye mesaj gönderme
        if (send(client_socket, message, strlen(message), 0) < 0) {
            perror("İstemciye mesaj gönderilemedi");
            exit(EXIT_FAILURE);
        }
        printf("Mesaj gönderildi\n");
    }
}