#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int signum) {
    if (signum == SIGUSR1) {
        printf("Receiver process: Hello\n");
    }
}

int main() {
    signal(SIGUSR1, signal_handler);

    while (1) {
        // Receiver process continues to run and wait for signals
        sleep(1);
    }

    return 0;
}
