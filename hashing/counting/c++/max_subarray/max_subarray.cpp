// max_subarray.cpp
#include "max_subarray.hpp"
#include <vector>
#include <unordered_map>

int maxSubarrayLength(const std::vector<int> &nums, int k)
{
    std::unordered_map<int, int> counts;
    int left = 0;
    int windowLen = 0;
    for (int right = 0; right < nums.size(); right++)
    {
        // Expand the window
        auto result = counts.try_emplace(nums[right], 1);
        // If key already exist, increment
        if (!result.second)
        {
            result.first->second++;
        }

        // If a count has exceeded k, the window has become invalid
        while (counts[nums[right]] > k)
        {
            // Shrink by decrementing the count of the element the left pointer points to
            counts[nums[left]]--;
            // Slide the window forward
            left++;
        }

        // Check if answer needs to be updated
        windowLen = std::max(windowLen, right - left + 1);
    }

    return windowLen;
}
