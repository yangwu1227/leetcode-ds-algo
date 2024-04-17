// min_start_value.cpp
#include "min_start_value.hpp"
#include <vector>

int minStartValue(const std::vector<int> &nums)
{
    // O(n) to build prefix sum and find minimum prefix sum in one go
    int prefixSum = 0, minSum = 0;
    for (const auto &num : nums)
    {
        prefixSum += num;
        minSum = std::min(minSum, prefixSum);
    }

    // Max returns (1 - minSum) for minSum < 0, so this positive value more than offsets minSum
    // If minSum >= 0, max returns at least 1
    return std::max(1, 1 - minSum);
}
