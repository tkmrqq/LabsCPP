#ifndef LAB4_MAIN_H
#define LAB4_MAIN_H

#include "exp.h"
#include "iostream"
#include "fstream"
#define MAX 100

template <class T>
class Stack{
    int top;
    T *data;
public:
    struct iterator {
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T *;  // or also value_type*
        using reference = T &;  // or also value_type&
        iterator(pointer ptr) : m_ptr(ptr) {}


        reference operator*() const { return *m_ptr; }
        pointer operator->() const { return m_ptr; }

        iterator& operator++() { m_ptr++; return *this; }
        iterator& operator+(int val) { m_ptr+=val; return *this; }

        iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp; }

        friend bool operator== (const iterator& a, const iterator& b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!= (const iterator& a, const iterator& b) { return a.m_ptr != b.m_ptr; };

    private:
        pointer m_ptr;
    };

    Stack(){
        top = 0;
        data = new T[0];
    }

    iterator begin() { return iterator(&data[0]); }
    iterator end() { return iterator(&data[top]); }

    bool isEmpty();
    bool isFull();
    bool push(const T& x);
    T pop();
    T peek();
    size_t size();
    void print();
    void swap(Stack &obj);

    void serialize(std::ostream& os) const {
        os.write(reinterpret_cast<const char*>(&top), sizeof(top));
        os.write(reinterpret_cast<const char*>(data), top * sizeof(T));
    }

    void deserialize(std::istream& is){
        is.read(reinterpret_cast<char*>(&top), sizeof(top));
        delete [] data;
        data = new T[top];
        is.read(reinterpret_cast<char*>(data), top * sizeof(T));
    }

    ~Stack(){
//        delete[] data;
    }
};

template<class T>
bool Stack<T>::isEmpty() {
    return (top < 1);
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
T Stack<T>::peek() {
    if (!isEmpty()) {
        return data[top-1];
    } else {
        throw Exp(102, "Stack is empty");
    }
}

template<class T>
size_t Stack<T>::size() {
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

template <class T>
void writeStackToFile(Stack<T>& myStack, std::string& filename) {
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        Stack<T> tempStack = myStack;
        while (!tempStack.isEmpty()) {
            outputFile << tempStack.peek();
            tempStack.pop();
        }
        outputFile.close();
    } else {
        throw Exp(200, "Can't open file to write");
    }
}

template <class T>
void readStackFromFile(Stack<T>& myStack, std::string& filename) {
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        T tempObject;

        while (inputFile >> tempObject) {
            myStack.push(tempObject);
        }
        inputFile.close();
    } else {
        throw Exp(201, "Can't open file to read");
    }
}


#endif//LAB4_MAIN_H
