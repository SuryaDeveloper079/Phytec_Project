#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024 // Define a constant buffer size for sending/receiving data

int main(int argc, char *argv[]) {

     //Check if user passed the port number as an argument
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", argv[0]);
        return 1;
    }


    const char *server_ip = argv[1]; // Read server IP from command-line argument

    int server_port = atoi(argv[2]); // Convert port string to int
    
    int sockfd; // Will store the socket file descriptor
    struct sockaddr_in server_addr; // Structure to store server address
    char buffer[BUFFER_SIZE]; // Buffer for sending and receiving the Message

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);    // To create the UDP Socket using IPv4(AF_INET) datagram Type(SOCK_DGRAM) #Socket API
    if (sockfd < 0) {
        // If socket creation fails, print error and exit
        perror("Socket creation failed");
        return 1;
    }

    // Clear out the server address structure (set all bytes to 0)
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;   // Set address family to IPv4
    server_addr.sin_port = htons(server_port);  // Convert port to network byte order
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);   // Convert IP string to binary

    socklen_t len = sizeof(server_addr);    // Length of the server address structure

    while (1) {
        // Send the Message to server
        printf("You: ");
        fgets(buffer, BUFFER_SIZE, stdin);  // Read message from standard input (keyboard)

        // Send the message to the server via UDP
        sendto(sockfd, buffer, strlen(buffer), 0,
               (const struct sockaddr *)&server_addr, len);
        

        // Wait for reply from the server (blocking)
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE - 1, 0,
                         (struct sockaddr *)&server_addr, &len);

        // Null-terminate received message                 
        buffer[n] = '\0';
        printf("Server: %s\n", buffer); // Print the server's reply

    }

    close(sockfd); // Close the socket (unreachable in infinite loop)
    return 0;
}
