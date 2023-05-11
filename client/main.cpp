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
    char file_path[] = "/home/leonard/Desktop/data_transfer_client/sended_files/file3.txt";

    File file(file_path);
    clientSocket client;

    // read file name, file size, and content.
    char * file_name = file.get_file_name(file_path); 
    int file_size = file.get_file_size();
    char * file_content = file.get_file_content();
    
    // send file name
    client.client_send(file_name);
    
    // send file size.
    client.client_send(file_size);

    // send file content.
    // client.client_send(file_content);

    std::ifstream &ifs = file.get_ifs();

    // Buffer size 1 Megabyte (or any number you like)
    size_t buffer_size = 1<<20;
    char *buffer = new char[buffer_size];

    while (ifs)
    {
        // Try to read next chunk of data
        ifs.read(buffer, buffer_size);
        // Get the number of bytes actually read
        size_t count = ifs.gcount();
        // If nothing has been read, break
        if (!count) 
            break;
        // Do whatever you need with first count bytes in the buffer
        // ...
    }

    delete[] buffer;

    return 0;
}

