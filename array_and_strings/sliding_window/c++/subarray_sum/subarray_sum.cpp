// subarray_sum.cpp
#include "subarray_sum.h"
#include <vector>

int findBestSubarray(const std::vector<int> &nums, const int &k)
{
    int currSum = 0;
    // First window contains elements from 0 to k - 1
    for (int i = 0; i < k; i++)
    {
        // Add the elements to the current sum tracker
        currSum += nums[i];
    }
    // After the first window, the answer is simply the sum of the first k elements
    int ans = currSum;
    // Slide the window towards the right
    for (int i = k; i < nums.size(); i++)
    {
        // Add the next/ith element and remove the (i - k)th so the window size stays fixed at k
        currSum += nums[i] - nums[i - k];
        // Literals are immutable and so 'ans' has not been changed yet
        // If the currSum is larger than answer, which is the previous window sum, update
        ans = std::max(ans, currSum);
    }

    return ans;
}
