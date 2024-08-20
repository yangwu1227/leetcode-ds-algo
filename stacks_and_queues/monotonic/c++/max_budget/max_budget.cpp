// max_budget.cpp
#include "max_budget.hpp"
#include <deque>
#include <vector>
#include <algorithm> // std::max

int maxBudget(const std::vector<int> &chargeTimes, const std::vector<int> &runningCosts, long long budget)
{
    int n = chargeTimes.size();
    if (n == 1)
    {
        return chargeTimes[0] + runningCosts[0] > budget ? 0 : 1;
    }

    int k = 0;
    int maxWindowSize = 0;
    long long sumRunningCost = 0; // Use long long int to prevent integer overflow
    int left = 0;
    std::deque<int> monotonicNonIncreasing;
    for (int right = 0; right < n; right++)
    {
        // While the deque is non-empty and the back of the deque is smaller than the current charge time
        while (!monotonicNonIncreasing.empty() && chargeTimes[monotonicNonIncreasing.back()] < chargeTimes[right])
        {
            // Remove the back element to maintain the non-increasing order
            monotonicNonIncreasing.pop_back();
        }
        monotonicNonIncreasing.push_back(right);
        sumRunningCost += runningCosts[right];
        k += 1;

        // While the current window has become invalid
        while (!monotonicNonIncreasing.empty() && chargeTimes[monotonicNonIncreasing.front()] + k * sumRunningCost > budget)
        {
            // If the element to be removed from the window is the current max element of the window
            if (monotonicNonIncreasing.front() == left)
            {
                // Pop the front of the deque
                monotonicNonIncreasing.pop_front();
            }
            k -= 1;
            sumRunningCost -= runningCosts[left];
            left += 1;
        }

        // Update max window size
        maxWindowSize = std::max(maxWindowSize, right - left + 1);
    }
    return maxWindowSize;
}
