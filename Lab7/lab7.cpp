//Классы контейнеры, итераторы, алгоритмы

#include "myStack.h"
#include <algorithm>


bool condition(int value){
    return value > 5;
}

bool compare(int a, int b){
    return a > b;
}

int main() {
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);

    Stack<int>::iterator it = stack.begin();
    Stack<int>::iterator end = stack.end();



    return 0;
}
