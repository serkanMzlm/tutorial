#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int received_signal = 0;

void signal_handler(int signum) {
    received_signal = signum;
}

int main() {
    int number;
    char message[10];

    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);

    printf("Receiver process: Waiting for signal...\n");
    while (received_signal != SIGUSR1) {
        usleep(100);
    }

    printf("Receiver process: Signal received\n");

    received_signal = 0; // Reset the signal variable

    while (received_signal != SIGUSR2) {
        usleep(100);
    }

    printf("Receiver process: Data received\n");

    return 0;
}
