// pivot_index.cpp
#include "pivot_index.hpp"
#include <vector>
#include <numeric> // For std::partial_sum

int pivotIndex(const std::vector<int> &nums)
{
    // O(n) for building prefix
    std::vector<long long> prefix(nums.size());
    std::partial_sum(nums.begin(), nums.end(), prefix.begin());

    // Total sum is the last element of the prefix sum array
    int totalSum = prefix.back();

    for (int i = 0; i < nums.size(); i++)
    {
        // Left sum is the sum of all elements before i, if i > 0
        int leftSum = (i > 0 ? prefix[i - 1] : 0);
        // Right sum is the difference between the total sum and prefix[i]
        // Since prefix[i] is the sum of all elements up to and including i
        int rightSum = totalSum - prefix[i];

        if (leftSum == rightSum)
        {
            return i;
        }
    }

    // If loop finishes without returning, no pivot index
    return -1;
}
