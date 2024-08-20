// main.cpp
#include "stack.hpp"
#include "rng_integer.hpp"
#include <vector>
#include <iostream>

int main()
{
    Stack stack = Stack();
    int numElements = generateRandomInteger(0, 100);

    for (int i = 0; i < numElements; i++)
    {
        int x = generateRandomInteger(0, 1000);
        stack.push(x);
    }

    std::cout << "Stack after pushing " << numElements << " random integers: " << stack << '\n';

    std::cout << "Popping the top of the stack: " << stack.pop() << '\n';

    std::cout << "Stack after popping the top: " << stack << '\n';

    std::cout << "Get the top of the stack: " << stack.top() << '\n';

    std::cout << "Check if the stack is empty: " << (stack.empty() ? "Yes" : "No") << '\n';

    std::cout << "Popping the top of the stack again: " << stack.pop() << '\n';

    std::cout << "Get the new top of the stack: " << stack.top() << '\n';

    std::cout << "Popping the top of the stack again: " << stack.pop() << '\n';

    std::cout << "Get the new top of the stack: " << stack.top() << '\n';

    std::cout << "Popping the top of the stack again: " << stack.pop() << '\n';

    std::cout << "Get the new top of the stack: " << stack.top() << '\n';

    std::cout << "Check if the stack is empty: " << (stack.empty() ? "Yes" : "No") << '\n';

    std::cout << "Popping all elements from the stack...\n";
    while (!stack.empty())
    {
        stack.pop();
    }

    std::cout << "Check if the stack is empty after popping all elements: " << (stack.empty() ? "Yes" : "No") << '\n';

    return 0;
}
