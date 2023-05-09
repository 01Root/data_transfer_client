#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <cstring>

#include "../utils/File.h"

#define PORT 8080
#define BUFFERSIZE 1024

using namespace std;

class clientSocket
{
    private:
        int client_fd;
        int addr_length;
        int connect_status;
        struct sockaddr_in address;
        char buffer[BUFFERSIZE] = {0};

    public:

        clientSocket();
        ~clientSocket();

        // socket creation 
        void client_socket_creation();

        // connection 
        void client_connection();

        // send message
        void client_send(char * message);
        void client_send (int message);

        // close
        void client_close();
};
