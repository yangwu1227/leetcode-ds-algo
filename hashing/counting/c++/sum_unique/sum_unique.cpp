// sum_unique.cpp
#include "sum_unique.hpp"
#include <vector>
#include <unordered_map>
#include <numeric>

int sumUnique(const std::vector<int> &nums)
{
    std::unordered_map<int, int> counts;
    for (const auto &num : nums)
    {
        auto result = counts.try_emplace(num, 1);
        // If the key already exist
        if (!result.second)
        {
            // Increment the count, results.first is the iterator pointing to the element
            // And second is the count value in (num, count) to be incremented
            result.first->second++;
        }
    }

    // Just for practice, just accumulate but a simple loop with structured bindings should do
    int uniqueSum = std::accumulate(
        nums.begin(), nums.end(), 0,
        [&counts](int currentCumSum, const auto nextNum)
        {
            // If the next element count is 1, add it, else skip by returning current cumulative sum
            return (counts[nextNum] == 1 ? currentCumSum + nextNum : currentCumSum);
        });

    return uniqueSum;
}
