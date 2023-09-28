#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    pid_t receiver_pid;

    printf("Enter the PID of the receiver process: ");
    scanf("%d", &receiver_pid);

    int number = 12345;
    char message[] = "Hello";

    printf("Sender process: Sending signal to receiver process\n");
    kill(receiver_pid, SIGUSR1);
    usleep(10000); // Wait a short time to ensure the receiver has set up its signal handler

    printf("Sender process: Sending data to receiver process\n");
    kill(receiver_pid, SIGUSR2);
    usleep(10000); // Wait for the receiver to print the data

    return 0;
}
