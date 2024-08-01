// queue_stack.hpp
#ifndef QUEUE_STACK_HPP
#define QUEUE_STACK_HPP
#include <iostream>
#include <stack>
#include <vector>

class QueueStack
{
public:
    /**
     * @brief Construct a new QueueStack instance.
     *
     */
    QueueStack();

    /**
     * @brief Push an element to the back of the queue.
     *
     * @param x The element to be added to the queue
     */
    void push(int x);

    /**
     * @brief Removes and returns the element from the front of the queue.
     *
     * @return int The element at the front of the queue
     */
    int pop();

    /**
     * @brief Returns the element at the front of the queue without removing it.
     *
     * @return int The element at the front of the queue
     */
    int peek() const;

    /**
     * @brief Predicate member function that checks if the queue is empty.
     *
     * @return bool `true` if the queue is empty, `false` otherwise.
     */
    bool empty() const;
private:
    std::stack<int, std::vector<int>> stack;          // Used to store all elements in the queue
    std::stack<int, std::vector<int>> stackReversed; // Used to store all elements in the queue in reverse order for FIFO operations
    int front; // Reference the front of the queue
};

#endif
