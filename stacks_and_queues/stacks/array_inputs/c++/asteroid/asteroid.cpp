// asteroid.cpp
#include "asteroid.hpp"
#include <vector>
#include <cmath>

std::vector<int> asteroid(const std::vector<int> &data)
{
    std::vector<int> dataStack;
    dataStack.reserve(data.size());
    for (const auto &val : data)
    {
        // If the stack is empty, or the current value is moving right, or the top of the stack is moving left
        if (dataStack.empty() || val > 0 || dataStack.back() < 0)
        {
            // Push the current value
            dataStack.push_back(val);
        }
        // If the stack is not empty and current value is moving left and top of the stack is moving right
        else
        {
            // Keep a variable to determine if the while loop was broken out of
            bool breakWhile;
            // Keep checking if the stack is empty and top of the stack is moving to the right
            while (!dataStack.empty() && dataStack.back() > 0)
            {
                int topAbs = std::abs(dataStack.back());
                int valAbs = std::abs(val);
                // If the top of the stack is smaller in size and use continue to check the while condition again
                if (topAbs < valAbs)
                {
                    dataStack.pop_back();
                    breakWhile = false;
                    continue;
                }
                // If the top of the stack and the current value are equal in size, pop
                else if (topAbs == valAbs)
                {
                    dataStack.pop_back();
                    breakWhile = true;
                    break;
                }
                // If the top of the stack is larger in size, do nothing
                else
                {
                    breakWhile = true;
                    break;
                }
            }
            // If loop exited without break, then all collisons are resolved, push the current value
            if (!breakWhile)
            {
                dataStack.push_back(val);
            }
        }
    }
    return dataStack;
}
