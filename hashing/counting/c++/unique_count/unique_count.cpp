// unique_count.hpp
#include "unique_count.hpp"
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iterator>

bool uniqueCount(const std::vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return true;
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

    // If all elements are unique with the same count, then this would cost O(n)
    std::unordered_set<int> setUniqueCounts;
    std::transform(
        // Iterate over the hash map
        counts.begin(), counts.end(),
        // An `std::insert_iterator` for inserting counts (at the end of the set)
        std::inserter(setUniqueCounts, setUniqueCounts.end()),
        // Lambda function to extract the count from each (num, count) pair
        [](const auto &pair)
        { return pair.second; });

    return (setUniqueCounts.size() == counts.size() ? true : false);
}
