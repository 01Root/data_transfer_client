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
    // 314 309 304
    char file_path[] = "/home/leonard/Desktop/data_transfer_client/sended_files/1M.txt";

    File file(file_path);
    clientSocket client;
    
    // send file name
    client.send_file_name(file);

    // send file size 
    client.send_file_size(file);

    // send file content.
    client.send_file_content(file);
    
    return 0;
}

