// sum_range.cpp
#include "sum_range.hpp"
#include <vector>
#include <numeric>   // For std::partial_sum
#include <stdexcept> // For std::out_of_range

// Definition for constructor
NumArray::NumArray(const std::vector<int> &inputs) : nums(inputs), prefix(inputs.size())
{
    // O(n) operation to build the prefix sum array
    std::partial_sum(nums.begin(), nums.end(), prefix.begin());
}

// Definition for sumRange
int NumArray::sumRange(const int left, const int right) const
{
    // Formula for subarray sum: (sum of elements up to right) - (sum of elements up to left) + (element pointed to by left)
    return prefix[right] - prefix[left] + nums[left];
}
