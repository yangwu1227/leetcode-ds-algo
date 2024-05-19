// max_freq.cpp
#include "max_freq.hpp"
#include <unordered_map>
#include <numeric>
#include <algorithm>

int maxFreq(const std::vector<int> &nums)
{
    // O(n) to build hash map
    std::unordered_map<int, int> counts;
    for (const auto &num : nums)
    {
        auto result = counts.try_emplace(num, 1);
        // If key already exists, increment
        if (!result.second)
        {
            result.first->second++;
        }
    }

    // O(n) to find the max elements
    auto maxIter = std::max_element(
        counts.begin(), counts.end(),
        [](const auto currentCount, const auto nextCount)
        {
            // Second is a member of the pair (num, count)
            return currentCount.second < nextCount.second;
        });
    int maxCount = maxIter->second;

    // O(n) in the worst case when all counts are equal
    int totalCount = std::accumulate(
        counts.begin(), counts.end(), 0,
        [&maxCount](int currentCumSum, const auto nextCount)
        {
            // If nextCount.second equals maxCount, then add it, or else skip by returning the current cumulative sum
            return (nextCount.second == maxCount ? currentCumSum + nextCount.second : currentCumSum);
        });

    return totalCount;
}
