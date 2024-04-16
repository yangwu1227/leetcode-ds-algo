// split_array.cpp
#include "split_array.hpp"
#include <vector>

int splitArray(const std::vector<int> &nums)
{
    // Build prefix
    std::vector<long> prefix = {nums[0]};
    for (int i = 1; i < nums.size(); i++)
    {
        prefix.push_back(prefix.back() + nums[i]);
    }

    // Use nums.size() - 1 since the second section must have at least 1 number
    int validSplits = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        // Since prefix[i] is the sum up to and including element i in `nums`
        long leftSum = prefix[i];
        // Subtract prefix[i] from prefix.back() gives the sum of elements i + 1 through n
        long rightSum = prefix.back() - prefix[i];
        validSplits += (leftSum >= rightSum);
    }

    return validSplits;
}
