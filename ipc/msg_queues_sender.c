#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MAX_SIZE 100
typedef struct{
  long mtype; /* type of the message */
  char mtext[MAX_SIZE];
} message_t;

int main(){
  key_t key;
  int msgid;
  message_t msg;
  int count = 1;
  key = ftok("data_file", 65);
  msgid = msgget(key, 0666 | IPC_CREAT);
  while (count <= 30) {
      msg.mtype = 1;
      sprintf(msg.mtext, "%d - Hello World", count);

      
      /* Eğer kuyruk dolu ise yeni eklemler yapılmasını sağlar. Bu sayede
      * verilerin kaybolmasını önler. Açık olan kısım ise kuyrugun boyutunu
      * artırmaktansa kuyrugun boşalmasını bekler.*/
      
      // if (msgsnd(msgid, &msg, sizeof(msg), IPC_NOWAIT) == -1) {
      //     perror("msgsnd");
      // } else {
      //     printf("Gönderilen Mesaj: %s\n", msg.mtext);
      //     count++;
      // }

      msgsnd(msgid, &msg, sizeof(msg), 0);
      printf("Sent data: %s\n", msg.mtext);
      count++;

      sleep(1);
  }
  msgctl(msgid, IPC_RMID, NULL);
  return 0;
}