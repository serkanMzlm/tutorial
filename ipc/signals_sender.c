#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    pid_t receiver_pid;

    printf("Enter the PID of the receiver process: ");
    scanf("%d", &receiver_pid);

    while (1) {
        printf("Sender process: Sending signal to receiver process\n");
        kill(receiver_pid, SIGUSR1);
        sleep(1);
    }

    return 0;
}
