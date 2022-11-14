#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

short socketCreate(void){
    short hSocket;
    printf("Create the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

int bindCreatedSocket(int hSocket){
    int iRetval = -1;
    int clientPort = 12345;

    struct sockaddr_in remote = {0};

    /* Internet address family */
    remote.sin_family = AF_INET;

    /* Any incoming inteface */
    remote.sin_addr.s_addr = htonl(INADDR_ANY);
    remote.sin_port = htons(clientPort); // Local port

    iRetval = bind(hSocket, (struct sockaddr *) &remote, sizeof(remote));
    return iRetval;
}

int main(int argc, char *argc[]){
    int socket_desc = 0, // the socket description (sockfd)
     sock = 0, clientLen = 0;
    struct sockaddr_in client;
    char client_message[200] = {0};
    char message[100] = {0};
    const chat *pMessage = "hello from Elor's server";

    // Create socket
    socket_desc = socketCreate();
    if (socket_desc == -1)
    {
        printf("Couldn't create socket\n");
        return 1;
    }

    printf("Socket created\n");

    // Bind
    if (bindCreatedSocket(socket_desc) < 0)
    {
        perror("bind failed.\n");
        return 1;
    }
    printf("bind done.\n");

    // Listen
    listen(socket_desc, 3); // max of 3 people can wait

    // Accept and incoming connection
    while (1)
    {
        printf("Waiting for incoming connections...\n");
        clientLen = sizeof(struct sockaddr_in);

        // accept connections from an incoming clients
        sock = accept(socket_desc, (struct sockaddr *) &client, (socklen_t*) &clientLen);

        if (sock < 0)
        {
            perror("accept failed.\n");
            return 1;
        }

        printf("Connection accepted\n");
        memset(client_message, '\0', sizeof client_message);
        memset(message, '\0', sizeof message);

        // Receive a reply from the client
        if (recv(sock, client_message, 200, 0) < 0)
        {
            printf("recv failed\n");
            return 1;
        }
        printf("Client reply: %s\n", client_message);

        if(strcmp(pMessage, client_message) == 0){
            strcpy(message, "Hi there!");
        }else{
            strcpy(message, "Invalid Message!");
        }

        // Send some data
        if (send(sock, message, strlen(message), 0) < 0)
        {
            printf("Send failed\n");
            return 1;
        }

        close(sock);
        sleep(1);
    }
    
}
