// main.cpp
#include "min_stack.hpp"
#include <iostream>
#include <stdlib.h> // For rand() and srand()
#include <stdio.h>  // For NULL
#include <time.h>   // For time

int main()
{

    // Set random seed
    MinStack minStack = MinStack();
    srand(time(NULL));
    int numElements = 5;
    for (int i = 0; i < numElements; i++)
    {
        int val = rand() % 1000 + 1;
        minStack.push(val);
    }
    std::cout << "MinStack after pushing " << numElements << " random integers: " << minStack << '\n';
    std::cout << "Top of the stack: " << minStack.top() << '\n';
    std::cout << "Minimum element in the stack: " << minStack.getMin() << '\n';
    minStack.pop();
    std::cout << "Min stack after popping the top element: " << minStack << '\n';
    std::cout << "Top of the stack: " << minStack.top() << '\n';
    std::cout << "Minimum element in the stack: " << minStack.getMin() << '\n';
    minStack.pop();
    std::cout << "Min stack after popping the top element: " << minStack << '\n';
    std::cout << "Top of the stack: " << minStack.top() << '\n';
    std::cout << "Minimum element in the stack: " << minStack.getMin() << '\n';

    return 0;
}
