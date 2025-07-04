#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h> // For socket functions and structures (sockaddr_in, htons, etc.)

#define BUFFER_SIZE 1024 // Define a constant buffer size for sending/receiving data

int main(int argc, char *argv[]) {

    //Check if user passed the port number as an argument.
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    //this line convert into string argument(argv[0]) to integer Port 
    int port = atoi(argv[1]);

    //This is the Socket File Discripter
    int sockfd;
    
    //Structure to hold the server client Address
    struct sockaddr_in server_addr, client_addr;

    //Character Buffer to store the message 
    char buffer[BUFFER_SIZE];

    // To create the UDP Socket using IPv4(AF_INET) datagram Type(SOCK_DGRAM) #Socket API
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    // if socket Creation fail to print yje error
    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }
//  This line sets all bytes of the (server_addr,client_addr)structure to zero.
    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));

    /* To configure the Server Address
    ** 1) To set the Address family to IPv4
    ** 2) To bind to any Local Ip Address
    ** 3) Convert port to network byte order and assign.
    */
    server_addr.sin_family = AF_INET; 
    server_addr.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces
    server_addr.sin_port = htons(port);

    //Bind the socket to the given port.
    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        return 1;
    }

    //length of the Client Address
    socklen_t len = sizeof(client_addr);

    printf("UDP Chat Server started on port %d\n", port);//Print the UDP server on which Port

    //Infinte Loop to handle message continuously
    while (1) {
        // Receive data from the Client
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE - 1, 0,
                         (struct sockaddr *)&client_addr, &len);

        buffer[n] = '\0';//Add null terminator so it becomes a proper C string
        printf("Client: %s\n", buffer);//Print the Buffer what message will get from the Client

        // Send reply to the Client
        printf("You: ");
        fgets(buffer, BUFFER_SIZE, stdin);//read user input to the buffer

        // Send the reply back to the same client using client_addr.
        sendto(sockfd, buffer, strlen(buffer), 0,
               (const struct sockaddr *)&client_addr, len);

    }
    //Close the  file Discripter
    close(sockfd);
    return 0;
}
