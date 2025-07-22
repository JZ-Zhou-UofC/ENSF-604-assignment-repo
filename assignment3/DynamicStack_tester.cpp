//
//  main.cpp
//  Dynamic Stack
//
//  Created by Mahmood Moussavi on 2024-04-09.
//

#include <iostream>
#include "DynamicStack.h"

int main() {
    
    DynamicStack *stack = new DynamicStack(5);
    std::cout << "Stack of 5 elements is created." << endl;
    std::cout << "\nPushing 4 into the stack ..." << endl;
    stack->push(122);
    stack->push(452);
    stack->push(322);
    stack->push(100);
    std::cout << "Expected vlues are: 122 452 322 100" << endl;
    std::cout << "Actual values are: ";
    stack->display();
    std::cout << "\nPoping 2 values from top of the stack ..." << endl;
    stack->pop();
    stack->pop();
    std::cout << "Expected vlues are : 122 452 " << endl;
    std::cout << "Actual values are: ";
    stack->display();
    std::cout << "\nPushing 8 more values into the stack ..." << endl;
    stack->push(1000);
    stack->push(2000);
    stack->push(3000);
    stack->push(4000);
    stack->push(5000);
    stack->push(10000);
    stack->push(13000);
    stack->push(14000);
    std::cout << "Expected vlues are : 122 452 1000 2000 3000 40000 4000 10000 13000 14000 " << endl;
    std::cout << "Actual values are: ";
    stack->display();
    
    std::cout << "\n Checking current size, capacity and the top value in the stack:" << endl;
    std::cout << stack->size() << endl;
    std::cout << stack->capacity() << endl;
    std::cout << stack->top() << endl;
    
    std::cout << "\nPoping 9 values from top of the stack ..." << endl;
    stack->pop();
    stack->pop();
    stack->pop();
    stack->pop();
    stack->pop();
    stack->pop();
    stack->pop();
    stack->pop();
    stack->pop();

    std::cout << "Expected vlues are : 122" << endl;
    std::cout << "Actual values are: ";
    stack->display();
    
    std::cout << "\nChecking current size, capacity and the top value in the stack:" << endl;
    std::cout << stack->size() << endl;
    std::cout << stack->capacity() << endl;
    std::cout << stack->top() << endl;
    
    std::cout << "\nChecking whether stack is emoty or not:" << endl;
    if(stack->empty())
        std::cout << "Yes: Stack is empty."<< endl;
    else
        std::cout << "Stack is not empty."<< endl;
    std::cout << "Stack still holds: " << endl;
    stack->display();
    return 0;
}
