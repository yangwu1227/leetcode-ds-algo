// queue_stack.cpp
#include "queue_stack.hpp"
#include <stack>
#include <vector>

QueueStack::QueueStack() : front(0), stack(), stackReversed() {};

void QueueStack::push(int x)
{
    // If stack is empty, add a reference to the first element in the queue
    if (this->stack.empty())
    {
        this->front = x;
    }
    // Push to the top of stack
    this->stack.push(x);
}

int QueueStack::pop()
{
    // If stackReversed is empty
    if (this->stackReversed.empty())
    {
        // Keep popping elements from stack and pushing these popped elements to the top of stackReversed
        while (!this->stack.empty())
        {
            this->stackReversed.push(this->stack.top());
            this->stack.pop();
        }
    }
    // Now, stackReversed should be ordered such that the front of the queue is at the top of this stack
    int poppedElement = this->stackReversed.top();
    this->stackReversed.pop();
    return poppedElement;
}

int QueueStack::peek() const
{
    // If queue is empty, throw a user friendly error
    if (this->empty())
    {
        throw std::out_of_range("Queue is empty");
    }
    // If stackReversed is non-empty, its top is the front of the queue
    if (!this->stackReversed.empty())
        return this->stackReversed.top();
    // If stackReversed is empty, then return this->front
    return this->front;
}

bool QueueStack::empty() const
{
    return this->stack.empty() && this->stackReversed.empty();
}
