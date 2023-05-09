#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H
#pragma once

#include <string>
#include <fstream>

class File
{
    private: 
        std::string file_path;
        std::ifstream ifs;

    public: 
        // constructor
        File();
        File (std::string file_path);

        // destructor
        ~File();

        // function 
        int get_file_size();
        char * get_file_name(char * file_path);
        char * get_file_content();
        std::ofstream file_creation(char * file_name);
};

#endif