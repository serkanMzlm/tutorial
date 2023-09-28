#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "mavlink/common/mavlink.h"

#define MY_IP "127.0.0.1"  // Alıcı IP adresi
#define MY_PORT 14550     // Alıcı Port numarası

int main() {
    int udp_port = 14550;  // Kendi UDP port numarası

    // UDP bağlantısı oluşturunuz
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in sockaddr;
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(udp_port);
    sockaddr.sin_addr.s_addr = INADDR_ANY;
    bind(sockfd, (struct sockaddr *)&sockaddr, sizeof(struct sockaddr_in));

    // Alıcı döngüsü
    while (true) {
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        ssize_t recsize = recv(sockfd, (void *)buffer, MAVLINK_MAX_PACKET_LEN, 0);

        if (recsize > 0) {
            // MAVLink mesajını işle
            mavlink_message_t msg;
            mavlink_status_t status;
            for (int i = 0; i < recsize; i++) {
                if (mavlink_parse_char(MAVLINK_COMM_0, buffer[i], &msg, &status)) {
                    // Mesaj başarıyla ayrıştırıldı
                    if (msg.msgid == MAVLINK_MSG_ID_HEARTBEAT) {
                        mavlink_heartbeat_t heartbeat;
                        mavlink_msg_heartbeat_decode(&msg, &heartbeat);
                        std::cout << "rx: " << heartbeat.custom_mode << std::endl;
                        if(heartbeat.custom_mode == 99){
                            break;

                        }
                    }
                }
            }
        }
    }

    close(sockfd);
    return 0;
}

