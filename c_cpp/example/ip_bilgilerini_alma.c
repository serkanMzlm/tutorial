#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Komutunun çağrılacağı sistem komutu
    char* command = "ifconfig | grep -oP '(?<=inet\\s)\\d+(\\.\\d+){3}'";
    char buffer[128];

    // Komutun çıktısını okumak için bir dosya işaretçisi
    FILE* pipe = popen(command, "r");
    if (!pipe) {
        perror("popen");
        return -1;
    }

    // Dosya okunduğu sürece devam et
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        // Satır sonundaki \n karakterini kaldır
        buffer[strcspn(buffer, "\n")] = 0;
        printf("IP address: %s\n", buffer);
    }

    pclose(pipe);
    return 0;
}
