#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h>
#include <chrono>
#include <thread>

#define PORT 8080

int client_socket;

void signal_handler(int signal) {
    if (signal == SIGINT) {
         printf("Soket Kapatıldı\n");
        close(client_socket);
        exit(EXIT_SUCCESS);
    }
}

int main() {
    struct sockaddr_in server_address;
    char server_response[1024];

    while (1) {
    // İstemci soketini oluşturma
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("İstemci soketi oluşturulamadı");
        exit(EXIT_FAILURE);
    }

    // Sunucu adresini yapılandırma
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    // Sunucu adresini belirleme
    if (inet_pton(AF_INET, "127.0.0.1", &(server_address.sin_addr)) <= 0) {
        perror("Geçersiz sunucu adresi");
        exit(EXIT_FAILURE);
    }

    // [CTRL+C](https://www.google.com/search?q=CTRL%2BC) tuş kombinasyonunu dinleme
    signal(SIGINT, signal_handler);

    // Sunucuya bağlanma
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Sunucuya bağlanılamadı");
        exit(EXIT_FAILURE);
    }

    // Sürekli olarak sunucudan yanıtı alma
    
        memset(server_response, 0, sizeof(server_response));
        if (recv(client_socket, server_response, sizeof(server_response), 0) < 0) {
            perror("Sunucudan yanıt alınamadı");
            exit(EXIT_FAILURE);
        }

        printf("Sunucudan gelen mesaj: %s\n", server_response);
        std::this_thread::sleep_for(std::chrono::seconds(1));  // Her bir sayı arasında 1 saniye bekle

    }
}