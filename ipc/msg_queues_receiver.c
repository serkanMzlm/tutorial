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
  
  /* "data_file" dosyası kullanılmasa bile kod doğru çalışır
    * fakat güvenlik açısından bulunması daha doğrudur.*/
  key = ftok("data_file", 65);
  msgid = msgget(key, 0666 | IPC_CREAT);

  while(1){
    msgrcv(msgid, &msg, sizeof(msg), 1, 0);
    printf("Received data: %s\n", msg.mtext);
    if(strncmp(msg.mtext, "30", 2) == 0){
      break;
    }
  } 
  
  msgctl(msgid, IPC_RMID, NULL);
  return 0;
}