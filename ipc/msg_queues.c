#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MAX_SIZE 100

struct message {
    long mtype;
    char mtext[MAX_SIZE];
};

int main() {
    key_t key;
    int msgid;
    struct message msg;

    /* farklı süreçler arasında iletişim kurmak için kullanılır.
    * ilk kısım dosya adı ikincisi ise project_id tutar. Fondkiyonda
    * belirtilen dosya o an o dizinde bulunmalıdır.*/
    key = ftok("ipc_example", 65);
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    /* Mesaj kuyrugu oluşturmak veya var olan bir mesaj kuyruğuna erişmek için 
    * kullanılır. Bir mesaj kuyrugu, süreçler arasında iletişim sağlamak için kullanılır.
    * IPC_CREAT kısmı mesaj kuyruğu oluşturmak için kullanılan bir flag'dır.*/
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    msg.mtype = 1;
    strcpy(msg.mtext, "Hello, this is an example of IPC!");
    if (msgsnd(msgid, &msg, sizeof(struct message) - sizeof(long), 0) == -1) {
        perror("msgsnd");
        exit(1);
    }
    printf("Send Msg: %s\n", msg.mtext);

    if (msgrcv(msgid, &msg, sizeof(struct message) - sizeof(long), 1, 0) == -1) {
        perror("msgrcv");
        exit(1);
    }
    printf("Received Msg: %s\n", msg.mtext);

    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }
    return 0;
}