// k_radius_avg.cpp
#include "k_radius_avg.hpp"
#include <vector>
#include <numeric> // For std::partial_sum

std::vector<int> findAverage(const std::vector<int> &nums, int k)
{
    int windowSize = k * 2 + 1;
    int n = nums.size();

    // Prefill with -1
    std::vector<int> avg(nums.size(), -1);

    // Handle special cases
    if (k == 0)
    {
        return nums;
    }
    if (windowSize > n)
    {
        return avg;
    }

    // Build prefix costing O(n)
    std::vector<long long> prefix = {nums[0]};
    prefix.reserve(n);
    for (int i = 1; i < n; i++)
    {
        prefix.push_back(prefix.back() + nums[i]);
    }

    // Iterate over elements with k elements before or after it
    for (int i = k; i < (n - k); i++)
    {
        int start = i - k;
        int end = i + k;
        long long subArraySum = prefix[end] - prefix[start] + nums[start];
        avg[i] = subArraySum / windowSize;
    }

    return avg;
}
