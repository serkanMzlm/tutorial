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
    int count = 1;

    key = ftok("shared_memory", 1234);

    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    if ((shm = (struct message *)shmat(shmid, NULL, 0)) == (struct message *)-1) {
        perror("shmat");
        exit(1);
    }

    while (count <= 30) {
        shm->count = count;
        sprintf(shm->mtext, "%d - Hello", count);
        printf("%d - Hello\n", count);
        count++;
        sleep(1);
    }

    shm->count = -1; // İşlem tamamlandı, -1 değeri gönderelim

    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
