// lucky_integer.cpp
#include "lucky_integer.hpp"
#include <vector>
#include <unordered_map>

int findLuckyInteger(const std::vector<int> &nums)
{
    // O(n) to build
    std::unordered_map<int, int> counts;
    for (const auto &num : nums)
    {
        auto result = counts.try_emplace(num, 1);
        // If the key already exists
        if (!result.second)
        {
            // Increment count
            result.first->second++;
        }
    }

    // O(n) to check
    int largestLuckyInteger = -1;
    for (const auto &[num, count] : counts)
    {
        if (num == count)
        {
            // Check if the answer should be updated
            largestLuckyInteger = std::max(largestLuckyInteger, num);
        }
    }

    return largestLuckyInteger;
}
