// validate_stack.cpp
#include "validate_stack.hpp"
#include <vector>
#include <stack>

bool validateStack(const std::vector<int> &pushed, const std::vector<int> &popped)
{
    if (pushed.size() == 1)
    {
        return pushed[0] == popped[0];
    }

    std::stack<int, std::vector<int>> stack;
    int poppedIndex = 0;
    for (auto &val : pushed)
    {
        // Push to stack
        stack.push(val);
        // As long as stack is non-empty and its top element is the same as the current popped element
        while (!stack.empty() && stack.top() == popped[poppedIndex])
        {
            // Pop the element from the stack
            stack.pop();
            // Increment the popped index to consider the next popped element
            ++poppedIndex;
        }
    }

    // If stack is empty, then the sequences of operations are valid, if not, then these sequences are not valid
    return stack.empty();
}
