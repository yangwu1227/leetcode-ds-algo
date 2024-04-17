// k_radius_avg.cpp
#include "k_radius_avg.hpp"
#include <vector>
#include <numeric> // For std::accumulate

std::vector<int> findAverage(const std::vector<int> &nums, int k)
{
    int windowSize = 2 * k + 1;
    // Prefill with -1
    std::vector<int> avg(nums.size(), -1);

    // In this case, no element has k elements before or after it
    if (windowSize > nums.size())
    {
        return avg;
    }
    // If k == 0, then the k-radius average for each element is itself
    if (k == 0)
    {
        return nums;
    }

    // First window costs O(windowSize)
    // Accumulate sums from [first, last) with a initial sum of 0LL
    long long firstWindowSum = std::accumulate(nums.begin(), nums.begin() + windowSize, 0LL);
    // The first index with enough elements before it is 'k', and so the first non -1 k-radius average is associated with that
    avg[k] = firstWindowSum / windowSize;

    // Only iterate through elements with valid window (i.e. k elements before or after)
    long long currentWindowSum = firstWindowSum;
    for (int i = k + 1; i < nums.size() - k; i++)
    {
        // These are the current window bounds
        int left = i - k;
        int right = i + k;
        // Expand the window by adding the next element pointed to by 'end'
        // Shrink the window (to keep it fixed) by removing the leftmost element pointed to by 'start - 1'
        currentWindowSum += (nums[right] - nums[left - 1]);
        avg[i] = currentWindowSum / windowSize;
    }

    return avg;
}
