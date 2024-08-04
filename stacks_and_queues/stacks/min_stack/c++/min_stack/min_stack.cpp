// min_stack.cpp
#include "min_stack.hpp"
#include <deque>
#include <iostream>
#include <limits>    // For std::numeric_limits<type_t>::max();
#include <algorithm> // For std::min

int MAX_PRINT_ELEMENTS = 4;

MinStack::MinStack() : dataStack(), minStack()
{
    minStack.push_back(std::numeric_limits<int>::max());
};

void MinStack::push(int val)
{
    this->dataStack.push_back(val);
    this->minStack.push_back(std::min(val, this->minStack.back()));
}

void MinStack::pop()
{
    this->dataStack.pop_back();
    this->minStack.pop_back();
}

int MinStack::top() const
{
    return this->dataStack.back();
}

int MinStack::getMin()
{
    return this->minStack.back();
}

std::ostream &operator<<(std::ostream &os, const MinStack &minStack)
{
    os << "MinStack([";
    int size = minStack.dataStack.size();
    int numElementsToPrint = std::min(size, MAX_PRINT_ELEMENTS);

    for (int i = 0; i < numElementsToPrint; ++i)
    {
        os << minStack.dataStack[i];
        if (i < numElementsToPrint - 1)
        {
            os << ", ";
        }
    }
    if (size > MAX_PRINT_ELEMENTS)
    {
        os << ", ...";
    }
    os << "])";
    return os;
}
