#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H
#pragma once

#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <cstring>

#include "../utils/File.h"

#define PORT 8080
#define BUFFER_SIZE 1024

using namespace std;

class clientSocket
{
    private:
        int client_fd;
        int addr_length;
        int connect_status;
        int send_status;
        struct sockaddr_in address;
        char buffer[BUFFER_SIZE] = {0};

    public:

        clientSocket();
        ~clientSocket();

        // get function 
        int get_client_fd();

        // socket creation 
        void client_socket_creation();

        // connection 
        void client_connection();
        
        // send message 
        void send_file_name(File &file);
        void send_file_size(File &file);
        void send_file_content (File &file);

        // close
        void client_close();
};

#endif