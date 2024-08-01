// queue_deque.cpp
#include "queue_deque.hpp"
#include <deque>

const int MAX_PRINT_ELEMENTS = 4;

QueueDeque::QueueDeque() : internalDeque{} {}

void QueueDeque::push(int x)
{
    this->internalDeque.push_back(x);
}

int QueueDeque::pop()
{
    int front = this->internalDeque.front();
    this->internalDeque.pop_front();
    return front;
}

int QueueDeque::peek() const
{
    return this->internalDeque.front();
}

bool QueueDeque::empty() const
{
    return this->internalDeque.empty();
}

std::ostream &operator<<(std::ostream &os, const QueueDeque &queue)
{
    os << "Queue([";
    int size = queue.internalDeque.size();
    int numElementsToPrint = std::min(size, MAX_PRINT_ELEMENTS);

    for (int i = 0; i < numElementsToPrint; ++i)
    {
        os << queue.internalDeque[i];
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
