#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#define KEY 1234
#define SEM_COUNT 0

int main() {
    int semid;
    key_t key;
    struct sembuf semaphore;

    // Öncelikle paylaşılan bellek bölgesini oluşturacağız
    key = ftok("data", KEY);
    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    int *sharedData = (int *)shmat(shmid, NULL, 0);
    *sharedData = 1;

    // Semaför oluşturacağız
    key = ftok("semaphore", KEY);
    semid = semget(key, 1, IPC_CREAT | 0666);
    if (semid < 0) {
        perror("semget");
        exit(1);
    }

    semaphore.sem_num = SEM_COUNT;
    semaphore.sem_op = 1;
    semaphore.sem_flg = 0;

    while (1) {
        // İlgili veriyi paylaşılan bellek bölgesine yazıyoruz
        *sharedData = (*sharedData) + 1;

        printf("Sender process: %d - Hello\n", *sharedData);
        semop(semid, &semaphore, 1);
        sleep(1);
    }

    shmdt(sharedData);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
