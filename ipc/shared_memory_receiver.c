#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

struct message {
    int count;
    char mtext[100];
};

int main() {
    int shmid;
    key_t key;
    struct message *shm;

    key = ftok("shared_memory", 1234);

    if ((shmid = shmget(key, SHM_SIZE, 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    if ((shm = (struct message *)shmat(shmid, NULL, 0)) == (struct message *)-1) {
        perror("shmat");
        exit(1);
    }

    printf("Receiver process is waiting for messages...\n");

    while (1) {
        if (shm->count == -1) {
            break; // İşlem tamamlandı, -1 değeri alındı
        }

        printf("Received message: %s\n", shm->mtext);
        sleep(1);
    }
    shmdt(shm);
    return 0;
}
