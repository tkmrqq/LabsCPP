#ifndef LAB4_MAIN_H
#define LAB4_MAIN_H

#include "exp.h"
#include "iostream"
#define MAX 2

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
    void swap(Stack &obj);

    ~Stack(){
        delete[] data;
    }
};

template<class T>
bool Stack<T>::isEmpty() {
    return (top < 0);
}

template<class T>
bool Stack<T>::push(const T& x) {
    if(!isFull()){
        T *temp = new T[top + 1];
        std::copy(data, data + top, temp);
        temp[top] = x;
        top++;
        delete[] data;
        data = temp;
        return true;
    }
    else {
        throw Exp(100, "Stack overflow!");
    }
}



template<class T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw Exp(101, "Stack is underflow!");
    }
    return data[top--];
}

template<class T>
T Stack<T>::topEl() {
    if(!isEmpty()){
        return data[top];
    }
    else {
        std::cout << "Stack is empty" << std::endl;
        return T();
    }
}

template<class T>
T Stack<T>::peek() {
    if (!isEmpty()) {
        return data[top];
    } else {
        throw Exp(102, "Stack is empty");
    }
}

template<class T>
T Stack<T>::size() {
    return top;
}

template<class T>
void Stack<T>::print() {
    for (int i = 0; i < top; ++i) {
        std::cout << data[i] << " ";
    }
}

template<class T>
bool Stack<T>::isFull(){
    return top == MAX - 1;
}

template<class T>
void Stack<T>::swap(Stack<T> &obj) {
    T *tempData = this->data;
    int tempTop = this->top;
    this->data = obj.data;
    this->top = obj.top;
    obj.data = tempData;
    obj.top = tempTop;
}

#endif//LAB4_MAIN_H
