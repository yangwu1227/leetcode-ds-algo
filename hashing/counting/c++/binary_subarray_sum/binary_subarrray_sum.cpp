// binary_subarray_sum.cpp
#include "binary_subarray_sum.hpp"
#include <unordered_map>
#include <vector>

int binarySubarraySum(const std::vector<int> &nums, int k)
{
    std::unordered_map<int, int> counts;
    // Start with empty array with a prefix sum of 0, increment its count
    counts[0]++;
    int subarrayWithSumKCount = 0, currentSum = 0;

    for (const auto &num : nums)
    {
        // Add to current sum
        currentSum += num;
        // We have seen `counts[current_sum - k]` more subarrays with sum = k since the last time the sum `current_sum - k` was seen
        // Add it to the running total count of valid subarrays seen so far
        subarrayWithSumKCount += counts[currentSum - k];
        // Add prefix sum as a key or increment the prefix sum count
        counts[currentSum]++;
    }

    return subarrayWithSumKCount;
}
