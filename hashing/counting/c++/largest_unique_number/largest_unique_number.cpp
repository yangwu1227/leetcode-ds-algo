// largest_unique_number.cpp
#include "largest_unique_number.hpp"
#include <vector>
#include <unordered_map>
#include <algorithm>

int largestUniqueNumber(const std::vector<int> &nums)
{
    std::unordered_map<int, int> counter;
    // O(n) to build the hash map
    for (const auto &num : nums)
    {
        auto result = counter.emplace(num, 1);
        // If the key already exists, increment it
        if (!result.second)
        {
            result.first->second++;
        }
    }

    // O(n) to check
    int maxInt = -1;
    for (const auto &[num, count] : counter)
    {
        if (count == 1)
        {
            maxInt = std::max(maxInt, num);
        }
    }

    return maxInt;
}
