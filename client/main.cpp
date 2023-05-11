#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <cstring>

#include "../utils/File.h"
#include "clientSocket.h"

#define PORT 8080

int main (void)
{
    ifstream is;

    // string file_path = "/home/leonard/Desktop/data_transfer_client/sended_files/1M.txt";
    // 314 309 304
    char file_path[] = "/home/leonard/Desktop/data_transfer_client/sended_files/1GB.txt";

    File file(file_path);
    clientSocket client;

    // read file name, file size, and content.
    char * file_name = file.get_file_name(file_path); 
    int file_size = file.get_file_size();
    // char * file_content = file.get_file_content();
    
    // send file name
    client.client_send(file_name);
    
    // send file size.
    client.client_send(file_size);

    // send file content.
    // client.client_send(file_content);
    client.client_send(file);
    

    return 0;
}

