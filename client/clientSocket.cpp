#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <cstring>

#include "../utils/File.h"
#include "clientSocket.h"

#define PORT 8080

clientSocket::clientSocket()
{
    client_socket_creation();
    client_connection();
}
clientSocket::~clientSocket()
{
    client_close();
}

// socket creation 
void clientSocket::client_socket_creation()
{
    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd < 0)
    {
        perror("client socket creation fail !!!!");
        exit(EXIT_FAILURE);
    }
}

// connection 
void clientSocket::client_connection()
{
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    address.sin_addr.s_addr = INADDR_ANY;
    addr_length = sizeof(address);
    connect_status = connect(client_fd, (struct sockaddr *) & address, sizeof(address));
    if (connect_status < 0)
    {
        perror("connection error");
        exit(EXIT_FAILURE);
    }
}

// send message
void clientSocket::client_send(char * message)
{
    memset(buffer, '0', sizeof(buffer));
    strcpy(buffer, message);
    send(client_fd, buffer, strlen(buffer) + 1, 0);

    cout << "The buffer is :" << buffer << "The buffer size is " << strlen(buffer) << endl;
    
}
void clientSocket::client_send (int message)
{
    memset(buffer, '0', sizeof(buffer));
    sprintf(buffer, "%d", message);
    send(client_fd, buffer, strlen(buffer) + 1, 0);

    cout << "The buffer is :" << buffer << "The buffer size is " << strlen(buffer) << endl;

}

// close
void clientSocket::client_close()
{
    close(client_fd);
}