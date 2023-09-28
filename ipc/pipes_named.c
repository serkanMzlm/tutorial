#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 256
#define FIFO_NAME "/tmp/ex_pipe"

int main() {
    char buffer[BUFFER_SIZE];

    /* Belirtilen isimde sistem üzerinde dosya oluşması
    * sağlanır. Bu sayede istenilen dosyadan erişim sağlanır.
    * "0666" dosyanın izinlerini ayarlanır. Eğer dosya varsa 
    * hata mesajı döndürür.*/
    mkfifo(FIFO_NAME, 0666);

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid > 0) {
        // parent süreç (yazma ucu)
        int fd = open(FIFO_NAME, O_WRONLY);
        if (fd == -1) {
            perror("open");
            exit(1);
        }

        write(fd, "Hello, child!", strlen("Hello, child!") + 1);
        close(fd);
        wait(NULL); // child sürecin tamamlanmasını bekliyor
    } else {
        // child süreç (okuma ucu)
        int fd = open(FIFO_NAME, O_RDONLY);
        if (fd == -1) {
            perror("open");
            exit(1);
        }

        read(fd, buffer, sizeof(buffer));
        printf("Message received: %s\n", buffer);
        close(fd);
    }

    return 0;
}
