#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Create a Socket for server communication
short socketCreate(void){
    short hSocket;
    printf("Create the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

// try to connect with server
int socketConnect(int hSocket){
    int iRetval = -1;
    int ServerPort = 12345;

    struct sockaddr_in remote = {0};
    remote.sin_addr.s_addr = inet_addr("127.0.0.1");
    remote.sin_family = AF_INET;
    remote.sin_port = htons(ServerPort);

    iRetval = connect(hSocket, (struct sockaddr *), &remote, sizeof(struct sockaddr *));
    return iRetval;
}

// Send the data to the server and set the timeout of 20 seconds
int socketSend(int hSocket, char *Rqst, short lenRqst){
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20;
    tv.tv_usec = 0;

    if (setsockopt(hSocket, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv, sizeof(tv)) < 0)
    {
        printf("Time out\n");
        return 1;
    }

    shortRetval = send(hSocket, Rqst, lenRqst, 0);
    return shortRetval;
}

// Receive the data to the server
int socketSend(int hSocket, char *Rsp, short RvcSize){
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20;
    tv.tv_usec = 0;

    if (setsockopt(hSocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv)) < 0)
    {
        printf("Time out\n");
        return 1;
    }

    shortRetval = recv(hSocket, Rsp, RvcSize, 0);
    printf("Response: %s\n", Rsp);
    return shortRetval;
}

// main driver program
int main(int argc, char *argv[]){
    int hSocket = 0, read_size = 0;
    struct sockaddr_in server;
    char sendToServer[100] = {0};
    char server_reply[200] = {0};

    // Create socket
    hSocket = socketCreate();

    if (hSocket == -1)
    {
        printf("Couldn't create socket\n");
        return 1;
    }

    printf("Socket is created\n");

    // Connect to remote server
    if (socketConnect(hSocket) < 0)
    {
        perror("Connect failed\n");
        return 1;
    }

    printf("Successfully connected with server\n");
    printf("Enter the Message: ");
    fgets(sendToServer, 100, stdin);

    // Send data to the server
    socketSend(hSocket, sendToServer, strnlen(sendToServer));

    // Received the data from the server
    read_size = socketReceive(hSocket, server_reply, 200);
    printf("Server Response: %s\n", server_reply);

    close(hSocket);
    
    return 0;
}
