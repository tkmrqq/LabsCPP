#include "myStack.h"

int main() {
//    Stack<int> stack, stack2;
//
//    for (int i = 1; i < 10; ++i) {
//        stack.push(i);
//    }
//    stack.print();
//    std::cout << "\n";
//
//    for(int j = 10; j < 40; j++){
//        stack2.push(j);
//    }
//    stack2.print();
//    std::cout << "\n";
//    stack.swap(stack2);
//
//    std::cout << "Swapped stack 1: ";
//    stack.print();
//    std::cout << "\nSwapped stack 2: ";
//    stack2.print();
//
//    std::cout << "\nSize of stack 2: " << stack2.size();
//    std::cout << "\nSize of stack: " << stack.size() << std::endl;
//
//    stack.print();
//    stack.pop();
//    std::cout << stack.topEl();
//    std::cout << "Peek: "<< stack.peek();
//    return 0;
    Stack<int> stack;
    try {
        stack.push(1);
        stack.push(1);
    }
    catch (Exp error){
        error.show();
    }
    return 0;
}
