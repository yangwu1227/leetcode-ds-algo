// daily_temperatures.cpp
#include "daily_temperatures.hpp"
#include <vector>
#include <stack>

std::vector<int> dailyTemperatures(const std::vector<int> &temperatures)
{
    if (temperatures.size() == 1)
    {
        return {0};
    }

    // Initialize with zeros
    std::vector<int> output(temperatures.size());
    std::stack<int, std::vector<int>> dayStack;
    int previousDayIndex = -1;
    for (int currentDayIndex = 0; currentDayIndex < temperatures.size(); currentDayIndex++)
    {
        // While the stack is non-empty and the top of the stack temperature is lower than the current temperature
        while (!dayStack.empty() && temperatures[dayStack.top()] < temperatures[currentDayIndex])
        {
            // Pop the top of the stack
            previousDayIndex = dayStack.top();
            dayStack.pop();
            // Compute the number of days since 'previousDayIndex' before we encountered a warmer temperature
            output[previousDayIndex] = currentDayIndex - previousDayIndex;
        }
        dayStack.push(currentDayIndex);
    }

    return output;
}
