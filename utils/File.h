#ifndef FILE_H
#define FILE_H
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
        std::ifstream & get_ifs();
        int get_file_size();
        char * get_file_name(char * file_path);
};

#endif