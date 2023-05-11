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

// get function 
int clientSocket::get_client_fd()
{
    return this->client_fd;
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
void clientSocket::client_send (File &file)
{
    memset(buffer, '0', sizeof(buffer));
    std::ifstream &ifs = file.get_ifs();
    while (ifs)
    {
        ifs.read(buffer, BUFFERSIZE);
        size_t count = ifs.gcount();
        send(client_fd, buffer, count, 0);
        if (!count)
        {
            break;
        }
    }
    cout << "sended completely." << endl;
}

// close
void clientSocket::client_close()
{
    close(client_fd);
}