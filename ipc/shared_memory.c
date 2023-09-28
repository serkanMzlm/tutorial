#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024

int main() {
    int shmid;
    key_t key;
    char *shm, *s;
    const char *message = "Merhaba, bu bir IPC!";

    // Özel bir anahtar oluşturuyoruz, aynı anahtarı diğer programda kullanacağız
    key = ftok("shared_memory_example", 65);

    // Paylaşılan bellek bölgesini oluşturuyoruz
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Paylaşılan bellek bölgesine bağlanıyoruz
    if ((shm = shmat(shmid, NULL, 0)) == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    // Paylaşılan bellek bölgesine mesajı yazıyoruz
    strcpy(shm, message);

    printf("Mesaj paylaşılan bellek bölgesine yazıldı: %s\n", shm);
    printf("Alınan mesaj: %s\n", shm);

    // Paylaşılan bellek bölgesinden çıkıyoruz
    shmdt(shm);

    // Paylaşılan bellek bölgesini silme
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
