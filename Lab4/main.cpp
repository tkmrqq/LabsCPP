#include "main.h"

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
        std::cout << "Stack overflow" << std::endl;
        return false;
    }
}



template<class T>
T Stack<T>::pop() {
    if (isEmpty()) {
        std::cout << "Underflow\n";
        exit(EXIT_FAILURE);
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
        exit(EXIT_FAILURE);
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

int main() {
    Stack<int> stack;

    for (int i = 1; i < 10002; ++i) {
        stack.push(i);
    }

    stack.print();
    std::cout << "Size is: " << stack.size() << std::endl;
    std::cout << "\n";
    stack.pop();
//    stack.print();
    return 0;
}
