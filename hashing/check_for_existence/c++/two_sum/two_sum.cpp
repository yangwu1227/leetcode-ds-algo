// two_sum.cpp
#include "two_sum.hpp"
#include <vector>
#include <unordered_map>

// Definition for onePassTwoSum
std::vector<int> Solution::onePassTwoSum(const std::vector<int> &nums, int target)
{
    std::unordered_map<int, int> hashMap;
    for (int i = 0; i < nums.size(); i++)
    {
        int diff = target - nums[i];
        // Or, hashMap.contains(diff), which is a C++ 20 addition
        // Find returns an iterator pointing to the element if it exists, or else it points to the end() iterator
        if (hashMap.find(diff) != hashMap.end())
        {
            std::vector<int> result = {hashMap[diff], i};
            // Sort since we want to compare the two implementations
            std::sort(result.begin(), result.end());
            return result;
        }
        hashMap[nums[i]] = i;
    }

    // Will never get here if each input `nums` is guaranteed a solution
    return {-1, -1};
}

// Definition for twoPassesTwoSum
std::vector<int> Solution::twoPassesTwoSum(const std::vector<int> &nums, int target)
{
    // O(n) to build the hash map
    std::unordered_map<int, int> hashMap;
    for (int i = 0; i < nums.size(); i++)
    {
        hashMap[nums[i]] = i;
    }

    // O(n) to check for existence, since each lookup is average O(1)
    for (int i = 0; i < nums.size(); i++)
    {
        int diff = target - nums[i];
        if ((hashMap.find(diff) != hashMap.end()) && (hashMap[diff] != i))
        {
            std::vector<int> result = {hashMap[diff], i};
            std::sort(result.begin(), result.end());
            return result;
        }
    }

    return {-1, -1};
}
