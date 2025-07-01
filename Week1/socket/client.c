#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>         // For close()
#include <arpa/inet.h>      // For inet_addr
#include <sys/socket.h>     // For socket functions

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[1024];

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Define the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  // Connect to localhost

    // Connect to the server
    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(client_socket);
        exit(1);
    }

    // Send message to server
    char *message = "Hello from client!";
    send(client_socket, message, strlen(message), 0);

    // Receive response from server
    recv(client_socket, buffer, sizeof(buffer), 0);
    printf("Server says: %s\n", buffer);

    // Close socket
    close(client_socket);

    return 0;
}

