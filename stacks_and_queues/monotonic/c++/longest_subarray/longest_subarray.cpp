// longest_subarray.cpp
#include "longest_subarray.hpp"
#include <vector>
#include <deque>

int longestSubarray(const std::vector<int> &nums, int limit)
{
    if (nums.size() == 1)
    {
        return 1;
    }

    std::deque<int> monotonicIncreasing;
    std::deque<int> monotonicDecreasing;
    int windowSize = 0, left = 0;

    for (int right = 0; right < nums.size(); right++)
    {
        // While the current element is breaking monotonicities, pop from the deques
        while (!monotonicIncreasing.empty() && monotonicIncreasing.back() > nums[right])
        {
            monotonicIncreasing.pop_back();
        }
        while (!monotonicDecreasing.empty() && monotonicDecreasing.back() < nums[right])
        {
            monotonicDecreasing.pop_back();
        }

        monotonicIncreasing.push_back(nums[right]);
        monotonicDecreasing.push_back(nums[right]);

        // Check if the window has become invalid, i.e., max_of_window - min_of_window > limit
        while (monotonicDecreasing.front() - monotonicIncreasing.front() > limit)
        {
            if (monotonicIncreasing.front() == nums[left])
            {
                monotonicIncreasing.pop_front();
            }
            if (monotonicDecreasing.front() == nums[left])
            {
                monotonicDecreasing.pop_front();
            }
            // Increment the left index to remove it from the window size calculations
            ++left;
        }

        // Check if a larger window size has been found
        windowSize = std::max(windowSize, right - left + 1);
    }

    return windowSize;
}
