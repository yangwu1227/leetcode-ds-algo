// stack.hpp
#ifndef STACK_HPP
#define STACK_HPP
#include <deque>
#include <iostream>

/**
 * @brief A class representing a stack using a deque for efficient LIFO opertions.
 */
class Stack
{
public:
    /**
     * @brief Construct a new Stack instance.
     */
    Stack();

    /**
     * @brief Push an integer `x` onto the stack.
     *
     * @param x The integer to be pushed onto the stack
     */
    void push(int x);

    /**
     * @brief Remove and return the top element of the stack.
     *
     * @return int The top element of the stack
     *
     * @throws std::out_of_range if the stack is empty
     */
    int pop();

    /**
     * @brief Return the top element of the stack without removing it.
     *
     * @return int The top element of the stack
     *
     * @throws std::out_of_range if the stack is empty
     */
    int top() const;

    /**
     * @brief Check if the stack is empty.
     *
     * @return bool `true` if the stack is empty, `false` otherwise
     */
    bool empty() const;

    /**
     * @brief Overloads the << operator to print the the stack.
     *
     * @param os The output stream
     * @param Stack The stack instance to be printed
     * @return std::ostream& The output stream with the stack data
     */
    friend std::ostream &operator<<(std::ostream &os, const Stack &stack);

private:
    std::deque<int> internalDeque; // Used to store the pushed elements
};

#endif
