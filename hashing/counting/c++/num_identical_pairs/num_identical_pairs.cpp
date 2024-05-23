// num_identical_pairs.cpp
#include "num_identical_pairs.hpp"
#include <unordered_map>
#include <vector>
#include <numeric>

int numIdenticalPairs(const std::vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return 0;
    }

    // O(n) to build
    std::unordered_map<int, int> counts;
    for (const auto &num : nums)
    {
        auto result = counts.try_emplace(num, 1);
        // If key already exists
        if (!result.second)
        {
            result.first->second++;
        }
    }

    // O(k) with k = number of unique elements
    int numPairs = std::accumulate(
        counts.begin(), counts.end(), 0,
        [](int currentCumSum, const auto &nextPair)
        {
            auto &[num, count] = nextPair;
            return currentCumSum + (count * (count - 1)) / 2;
        });

    return numPairs;
}
