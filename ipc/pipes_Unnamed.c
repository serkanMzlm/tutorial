#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 256

int main() {
    int pipefd[2];
    char buffer[BUFFER_SIZE];

    
    /* pipe() fonksiyonu IPC için Unnamed Pipe oluşturur.
    * bu fonksiyon iki dosya tanımlayıcısı döndürür ve
    * tanımlayıcılar child part ve parent part arasında 
    * unnamed bir pipes oluşturmak için kullanılır.*/
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(1);
    }

    /* yeni bir süreç oluşturmak için kullanılır. İşletim
    * sisteminde çalışan bir programın bir kopyasını oluşturur.
    * Ve bu sayede iki ayrı süreç(parent ve child) oluşmuş olur.
    * POSIX standarına uygun işletim sistemlerinde kullanılır.*/
    pid_t pid = fork(); // PID = Process ID

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid > 0) {
        close(pipefd[0]); // Okuma ucu kapatılıyor
        write(pipefd[1], "Hello, child!", 14);
        close(pipefd[1]); // Yazma ucu kapatılıyor
        wait(NULL); 
    } else {
        close(pipefd[1]); // Yazma ucu kapatılıyor
        read(pipefd[0], buffer, BUFFER_SIZE);
        printf("Message received: %s\n", buffer);
        close(pipefd[0]); // Okuma ucu kapatılıyor
    }

    return 0;
}