#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>         // For close()
#include <arpa/inet.h>      // For inet_addr
#include <sys/socket.h>     // For socket functions

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    socklen_t addr_size;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Define the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);              // Port number
    server_addr.sin_addr.s_addr = INADDR_ANY;        // Accept connections from any IP

    // Bind the socket
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(1);
    }

    // Listen for connections
    listen(server_socket, 5);
    printf("Server listening on port 8080...\n");

    // Accept a client connection
    addr_size = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_size);
    if (client_socket < 0) {
        perror("Accept failed");
        close(server_socket);
        exit(1);
    }

    // Receive data from client
    recv(client_socket, buffer, sizeof(buffer), 0);
    printf("Client says: %s\n", buffer);

    // Send response to client
    char *response = "Hello from server!";
    send(client_socket, response, strlen(response), 0);

    // Close sockets
    close(client_socket);
    close(server_socket);

    return 0;
}

