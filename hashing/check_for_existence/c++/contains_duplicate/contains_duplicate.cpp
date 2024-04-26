// contains_duplicate.cpp
#include "contains_duplicate.hpp"
#include <vector>
#include <unordered_set>

bool containsDuplicate(const std::vector<int> &nums)
{
    // O(n) to build the set
    std::unordered_set<int> numSet;
    for (const auto &num : nums)
    {
        // Look up 0(1) to see if num already exists
        if (numSet.find(num) != numSet.end())
        {
            return true;
        }
        // Cost O(1)
        numSet.insert(num);
    }
    return false;
}
