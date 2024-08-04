// min_stack.hpp
#ifndef MIN_STACK_HPP
#define MIN_STACK_HPP
#include <deque>
#include <stack>

/**
 * @class ListNode
 * @brief MinStack is a stack data structure that supports push, pop, top, and retrieving the minimum element in constant time.
 */
class MinStack
{
public:
    /**
     * @brief Construct a new Min Stack instance.
     */
    MinStack();

    /**
     * @brief Pushes an element onto the stack.
     *
     * @param val The value to push onto the stack
     */
    void push(int val);

    /**
     * @brief Removes the element on the top of the stack.
     */
    void pop();

    /**
     * @brief Gets the top element of the stack.
     *
     * @return int The top element of the stack
     */
    int top() const;

    /**
     * @brief Retrieves the minimum element in the stack.
     *
     * @return int The minimum element in the stack
     */
    int getMin();

    /**
     * @brief Overloads the << operator to print the first x elements of the min stack.
     *
     * @param os The output stream
     * @param MinStack The min stack instance to be printed
     * @return std::ostream& The output stream with the min stack data
     */
    friend std::ostream &operator<<(std::ostream &os, const MinStack &minStack);

private:
    std::deque<int> dataStack;
    std::deque<int> minStack;
};

#endif
