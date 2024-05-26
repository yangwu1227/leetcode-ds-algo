// max_subarray_unique.cpp
#include "max_subarray_unique.hpp"
#include <vector>
#include <unordered_map>

int maxSubarrayUnique(const std::vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }

    int left = 0, maxSum = 0, currentSum = 0;
    std::unordered_map<int, int> counts;
    // O(n) operation
    for (int right = 0; right < nums.size(); right++)
    {
        // Increment the count of the nums[right] and add it to the current window sum
        auto result = counts.try_emplace(nums[right], 1);
        if (!result.second)
        {
            result.first->second++;
        }
        currentSum += nums[right];

        // If any element's count exceeds 1, the window has become invalid
        while (counts[nums[right]] > 1)
        {
            // Decrement the count of the element pointed to by the left pointer
            counts[nums[left]]--;
            // Subtract nums[left] from the current sum
            currentSum -= nums[left];
            // Slide the window rightward
            left++;
        }
        // Check if we have found a larger subarray sum
        maxSum = std::max(maxSum, currentSum);
    }

    return maxSum;
}
