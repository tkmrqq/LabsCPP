#ifndef LABSCPP_FILEPROC_H
#define LABSCPP_FILEPROC_H

#include "cstring"
#include "fstream"
#include "inheritance.h"
#include "myStack.h"
#include "variant8.cpp"

class File {
    char filename[80];
    std::fstream *fstr;
public:
    File(const char *filename);
    ~File();
    int open();
    int openForRead();
    const char *getName();

    //write to file
    template<class T>
    void writeStack(Stack<T> &myStack);
    template<class T>
    void writeStackBin(Stack<T> &myStack);

    //read file
    template<class T>
    void readStack(Stack<T> &myStack);
    template<class T>
    Stack<T> readStackBin();

    void remote();
    int del();
};

File::File(const char *filename_t) {
    strncpy(filename, filename_t, 80);
    fstr = new std::fstream;
}

File::~File() {
    if (fstr->is_open()) {
        fstr->close();
    }
    delete fstr;
}

int File::open() {
    fstr->open(filename, std::ios::in | std::ios::out | std::ios::trunc);
    if (!fstr->is_open()) return -1;
    return 0;
}

int File::openForRead() {
    fstr->open(filename, std::ios::in);
    if (!fstr->is_open()) return -1;
    return 0;
}


const char *File::getName() {
    return this->filename;
}

template<class T>
void File::writeStack(Stack<T> &myStack) {
    if (fstr->is_open()) {
        Stack<T> tempStack = myStack;
        while (!tempStack.isEmpty()) {
            *fstr << tempStack.peek();
            tempStack.pop();
        }
        fstr->close();
    } else {
        throw Exp(200, "Can't open file to write");
    }
}

template<class T>
void File::writeStackBin(Stack<T> &myStack) {
    std::ostream &os = *fstr;
    if (fstr->is_open()) {
        myStack.serialize(os);
    }
}

template<class T>
void File::readStack(Stack<T> &myStack) {
    if (fstr->is_open()) {
        T tempObject;
        while (*fstr >> tempObject) {
            myStack.push(tempObject);
        }
    } else {
        throw Exp(201, "Can't open file to read");
    }
//    return myStack;
}

template<class T>
Stack<T> File::readStackBin() {
    Stack<T> myStack;
    if (fstr->is_open()) {
        myStack.deserialize(*fstr);
    }
    return myStack;
}


#endif//LABSCPP_FILEPROC_H
