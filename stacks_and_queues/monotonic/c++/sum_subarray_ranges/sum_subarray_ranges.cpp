// sum_subarray_ranges.cpp
#include "sum_subarray_ranges.hpp"
#include <vector>
#include <stack>

long long int sumSubarrayRanges(const std::vector<int> &nums)
{
    int n = nums.size();
    long long int output = 0;

    if (n == 1)
    {
        return 0;
    }

    std::stack<int, std::vector<int>> monotonicIncreasing;
    for (int right = 0; right < n + 1; right++)
    {
        // While the stack is non-empty and the top of the stack is greater than or equal to nums[right]
        while (!monotonicIncreasing.empty() && (right == n || nums[monotonicIncreasing.top()] >= nums[right]))
        {
            // Calculations for the element at the top of the stack can be carried out at this point
            long long int topStackIndex = monotonicIncreasing.top();
            monotonicIncreasing.pop();
            long long int left = monotonicIncreasing.empty() ? -1 : monotonicIncreasing.top();
            // 1. (topStackIndex - left) is the number of starting positions of subarrays with nums[topStackIndex] as its minimum
            // 2. (right - topStackIndex) is the number of ending positions of subarrays with nums[topStackIndex] as its minimmum
            output -= nums[topStackIndex] * (topStackIndex - left) * (right - topStackIndex);
        }
        monotonicIncreasing.push(right);
    }

    std::stack<int, std::vector<int>> monotonicDecreasing;
    for (int right = 0; right < n + 1; right++)
    {
        // While the stack is non-empty and the top of the stack is less than or equal to nums[right]
        while (!monotonicDecreasing.empty() && (right == n || nums[monotonicDecreasing.top()] <= nums[right]))
        {
            // Calculations for the element at the top of the stack can be carried out at this point
            long long int topStackIndex = monotonicDecreasing.top();
            monotonicDecreasing.pop();
            long long int left = monotonicDecreasing.empty() ? -1 : monotonicDecreasing.top();
            // 1. (topStackIndex - left) is the number of starting positions of subarrays with nums[topStackIndex] as its maximum
            // 2. (right - topStackIndex) is the number of ending positions of subarrays with nums[topStackIndex] as its maximum
            output += nums[topStackIndex] * (topStackIndex - left) * (right - topStackIndex);
        }
        monotonicDecreasing.push(right);
    }

    return output;
}
