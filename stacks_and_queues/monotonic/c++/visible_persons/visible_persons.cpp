// visible_persons.cpp
#include "visible_persons.hpp"
#include <vector>
#include <stack>

std::vector<int> visiblePersons(const std::vector<int> &heights)
{
    if (heights.size() == 1)
    {
        return {0};
    }

    std::stack<int, std::vector<int>> monotonicDecreasing;
    std::vector<int> output(heights.size());
    for (int i = heights.size() - 1; i > -1; i--)
    {
        // Initialize the visible count of the current person to 0
        int visible = 0;
        // While the stack is non-empty and the current person is taller than the top of the stack person
        while (!monotonicDecreasing.empty() && heights[monotonicDecreasing.top()] < heights[i])
        {
            // Increment the visible count and pop the shorter top of the stack person since he is seen now
            visible += 1;
            monotonicDecreasing.pop();
        }
        // If the stack is non-empty after the while loop finishes, then the top of the stack is the last visible person to the right of current person, add him to the count
        if (!monotonicDecreasing.empty())
        {
            visible += 1;
        }
        monotonicDecreasing.push(i);
        output[i] = visible;
    }

    return output;
}
