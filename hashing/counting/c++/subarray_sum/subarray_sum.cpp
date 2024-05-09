// subarray_sum.cpp
#include "subarray_sum.hpp"
#include <vector>
#include <unordered_map>

int subarraySum(const std::vector<int> &nums, int k)
{
    // Initialize the hash map with the prefix sum of the empty subarray
    std::unordered_map<int, int> counts;
    counts[0]++;
    int currSum = 0, subarrayWithSumKCount = 0;

    for (const auto &num : nums)
    {
        // Add to the current prefix sum
        currSum += num;
        // Update the answer, which is the count of the prefix sum (curr_sum - k)
        subarrayWithSumKCount += counts[currSum - k];
        // Keep track of the count of each prefix sum
        counts[currSum]++;
    }

    return subarrayWithSumKCount;
}
