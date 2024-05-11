// subarray_odd.cpp
#include "subarray_odd.hpp"
#include <vector>
#include <unordered_map>

int subarrayOdd(const std::vector<int> &nums, int k)
{
    std::unordered_map<int, int> counts;
    counts[0]++;
    int currentOddCount = 0, totalOddCount = 0;
    // O(n)
    for (const auto &num : nums)
    {
        currentOddCount += (num & 1);
        totalOddCount += counts[currentOddCount - k];
        // Keep track of each odd count encountered
        counts[currentOddCount]++;
    }

    return totalOddCount;
}
