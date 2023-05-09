#include <string>
#include <iostream>
#include <sys/stat.h> // for struct stat
#include <fstream>
#include <libgen.h>

#include "File.h"


// constructor 
File::File (std::string file_path)
{
    this->file_path = file_path;
}
File::File(){}

// destructor 
File::~File()
{
    ifs.close();
}

// function 
int File::get_file_size()
{
    char * cfile_path = (char *) file_path.data();
    if (NULL == cfile_path)
    {
        return 0;
    }

    struct stat statbuf;
    stat (cfile_path, &statbuf);
    size_t file_size = statbuf.st_size;
    return file_size;
}

char* File::get_file_name(char * file_path)
{
    char * file_name = basename(file_path);

    return file_name;
}
char * File::get_file_content()
{
    int length;

    // open the input file and go to the end.
    ifs.open(file_path);     
    ifs.seekg(0, std::ios::end);    

    // get the length;
    length = ifs.tellg();           

    // back to the beginning.
    ifs.seekg(0, std::ios::beg);    
    
    // read the whole file into the buffer.
    char * buffer = new char[length];    
    ifs.read(buffer, length);                   
    
    return buffer;
}


std::ofstream File::file_creation(char * file_name)
{
    std::ofstream recv_file (file_name);
    return recv_file;
}