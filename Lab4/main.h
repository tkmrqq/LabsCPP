#ifndef LAB4_MAIN_H
#define LAB4_MAIN_H

#include "iostream"
#define MAX 10000

template <class T>
class Stack{
    int top;
    T *data;
public:
    Stack(){
        top = 0;
        data = new T[0];
    }

    bool isEmpty();
    bool isFull();
    bool push(const T& x);
    T pop();
    T topEl();
    T peek();
    T size();
    void print();

    ~Stack(){
//        delete[] data;
        std::cout << "Destruct!";
    }
};


#endif//LAB4_MAIN_H
