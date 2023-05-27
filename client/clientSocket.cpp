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
void clientSocket::send_file_name(File &file)
{
    char * file_name = file.get_file_name();

    memset(buffer, '0', sizeof(buffer));
    strcpy(buffer, file_name);

    send_status = send(client_fd, buffer, sizeof(buffer), 0);

    cout << "The buffer is :" << buffer << endl;
}
void clientSocket::send_file_size(File &file)
{
    int file_size = file.get_file_size();

    memset(buffer, '0', sizeof(buffer));
    sprintf(buffer, "%d", file_size);
    send(client_fd, buffer, BUFFERSIZE, 0);

    cout << "The buffer is :" << buffer << "The buffer size is " << strlen(buffer) << endl;
}
void clientSocket::send_file_content (File &file)
{
    std::cout << "start send file content." << std::endl;
    memset(buffer, '0', sizeof(buffer));
    std::ifstream &ifs = file.get_ifs();
    while (ifs)
    {
        ifs.read(buffer, BUFFERSIZE);
        size_t count = ifs.gcount();
        // for (int i = 0; i < 1024; ++i)
        // {
        //     std::cout << buffer[i];
        // }
        send(client_fd, buffer, BUFFERSIZE, 0);
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