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
    ifs.open(file_path, std::ios::in | std::ios::binary);
}
File::File(){}

// destructor 
File::~File()
{
    ifs.close();
}

// function 
std::ifstream& File::get_ifs()
{
    return this->ifs;
}

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