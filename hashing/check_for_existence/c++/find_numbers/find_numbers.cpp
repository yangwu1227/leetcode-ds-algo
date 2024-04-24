// find_numbers.cpp
#include "find_numbers.hpp"
#include <vector>
#include <unordered_set>

std::vector<int> findNumbers(const std::vector<int> &nums)
{
    // O(n) conversion
    std::unordered_set<int> numSet(nums.begin(), nums.end());

    // O(n) to check for existence
    std::vector<int> result;
    result.reserve(nums.size());
    for (const auto &num : numSet)
    {
        if ((numSet.find(num + 1) == numSet.end()) && (numSet.find(num - 1) == numSet.end()))
        {
            result.push_back(num);
        }
    }

    return result;
}
