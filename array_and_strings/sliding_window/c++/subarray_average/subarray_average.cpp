// subarray_average.cpp
#include "subarray_average.h"
#include <vector>

double findMaxAverage(const std::vector<int> &nums, const int &k)
{
    int currSum = 0;
    // First window
    for (int i = 0; i < k; i++)
    {
        currSum += nums[i];
    }
    double ans = static_cast<double>(currSum) / k;
    // Slide window
    for (int i = k; i < nums.size(); i++)
    {
        currSum += nums[i] - nums[i - k];
        double avg = static_cast<double>(currSum) / k;
        ans = std::max(ans, avg);
    }
    return ans;
}
