// max_length.cpp
#include "max_length.hpp"
#include <vector>
#include <unordered_map>

int findMaxLength(const std::vector<int> &nums)
{
    int maxLen = 0, count = 0;
    // Need to initialize count 0 at index -1, so if we encounter a count of 0 at some later index i, the subarray length is (i - (-1)) = i + 1
    // E.g., if by index 5 we have the same number of 1's and 0's, (5 - (-1)) = 6, the first 6 elements form a valid subarray
    std::unordered_map<int, int> hashMap;
    hashMap[0] = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        // Increment if 1 or decrement if 0
        count += (nums[i] ? 1 : -1);
        // Because we can only increment and decrement, the fact that hashMap.contain(count) exists means that count has returned to a previously seen value
        // This means that the increase and decrease in counts have balanced each other out between the previous and current indices (i.e. same number of 1's and 0's)
        if (hashMap.find(count) != hashMap.end())
        {
            // If hash_map[count] is the index where the first time the value count was observed
            // Then, (current) index - hash_map[count] gives the length of this valid subarray
            maxLen = std::max(maxLen, i - hashMap[count]);
        }
        else
        {
            // If we have not since count previously, store the current index as the first occurrence of this count
            hashMap[count] = i;
        }
    }

    return maxLen;
}
