#ifndef LABSCPP_LAB6_H
#define LABSCPP_LAB6_H

#include "fstream"
#include "cstring"

class File{
    char filename[80];
    std::fstream *fstr;
    int maxpos;
public:
    File(char *filename);
    ~File();
    int open();
    const char* getName();
    void remote();
    int del();
};

File::File(char *filename_t) {
    strncpy(filename, filename_t, 80);
    fstr = new std::fstream;
}

File::~File(){
    fstr->close();
    delete fstr;
}

int File::open() {
    fstr->open(filename, std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);
    if (!fstr->is_open()) return -1;
    return 0;
}

const char* File::getName() {
    return this->filename;
}



#endif//LABSCPP_LAB6_H
