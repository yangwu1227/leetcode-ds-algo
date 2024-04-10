// min_subarray_len.cpp
#include "min_subarray_len.h"
#include <vector>
#include <limits.h>

int minSubarrayLen(const std::vector<int> &nums, int target)
{
    int currSum = 0, left = 0;
    int windowLen = INT_MAX;

    for (int right = 0; right < nums.size(); right++)
    {
        // Add the next element from the right
        currSum += nums[right];
        // Once we achieve currSum >= target, we can no longer find another valid, smaller window anymore, need to shrink
        while (currSum >= target)
        {
            // Check if the current window size is smaller than the previous one
            windowLen = std::min(windowLen, right - left + 1);
            // Shrink the window from the left
            currSum -= nums[left];
            left++;
        }
    }

    // Return 0 if no such subarray is found, and the window length remains INT_MAX
    return (windowLen != INT_MAX) ? windowLen : 0;
}
