// queue_deque.hpp
#ifndef QUEUE_DEQUE_HPP
#define QUEUE_DEQUE_HPP
#include <deque>
#include <iostream>

class QueueDeque
{
public:
    /**
     * @brief Construct a new QueueDeque instance.
     *
     */
    QueueDeque();

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

    /**
     * @brief Overloads the << operator to print the first 4 elements of the queue.
     *
     * @param os The output stream
     * @param QueueDeque The queue instance to be printed
     * @return std::ostream& The output stream with the queue data
     */
    friend std::ostream &operator<<(std::ostream &os, const QueueDeque &queue);

private:
    std::deque<int> internalDeque; // Used to store all elements in the queue
};

#endif
