// stack.cpp
#include "stack.hpp"
#include <deque>
#include <stdexcept> // For std::out_of_range
#include <iostream>

Stack::Stack() : internalDeque() {};

void Stack::push(int x)
{
    this->internalDeque.push_back(x);
}

int Stack::pop()
{
    if (this->empty())
    {
        throw std::out_of_range("Stack is empty");
    }
    int popped = this->internalDeque.back();
    this->internalDeque.pop_back();
    return popped;
}

int Stack::top() const
{
    if (this->empty())
    {
        throw std::out_of_range("Stack is empty");
    }
    return this->internalDeque.back();
}

bool Stack::empty() const
{
    return this->internalDeque.empty();
}

std::ostream &operator<<(std::ostream &os, const Stack &stack)
{
    os << "Stack([";
    int size = stack.internalDeque.size();

    for (int i = 0; i < size; i++)
    {
        os << stack.internalDeque[i];
        if (i < size - 1)
        {
            os << ", ";
        }
    }
    os << "])";
    return os;
}
