#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  // for sleep()

void job() {
    time_t now;
    time(&now);
    printf("Task executed at %s", ctime(&now));
}

int main() {
    int interval = 5; // Run every 5 seconds

    printf("Scheduler started. Running task every %d seconds.\n", interval);

    while (1) {
        job();               // Call the task
        sleep(interval);     // Wait for next run
    }

    return 0;
}

