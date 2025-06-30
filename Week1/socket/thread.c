#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Thread function that receives and prints a message
void* print_message(void* arg) {
    char* message = (char*)arg;  // Cast the void* back to char*
    printf("%s\n", message);
    return NULL;
}

int main(int argc, char* argv[]) {
    pthread_t t1, t2;

    // Check if enough arguments are provided
    if (argc < 3) {
        printf("Usage: %s <message1> <message2>\n", argv[0]);
        return 1;
    }

    // Create thread 1 with first argument
    pthread_create(&t1, NULL, print_message, argv[1]);

    // Create thread 2 with second argument
    pthread_create(&t2, NULL, print_message, argv[2]);

    // Wait for both threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Main thread done.\n");
    return 0;
}

