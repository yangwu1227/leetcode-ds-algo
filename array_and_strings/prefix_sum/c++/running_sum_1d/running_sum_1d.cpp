// running_sum_1d.cpp
#include "running_sum_1d.hpp"
#include <vector>

void runningSum(std::vector<int> &nums)
{
    // Modify the vector in place, start at index 1 since the the first element of the running sum is just nums[0]
    for (int i = 1; i < nums.size(); i++)
    {
            nums[i] += nums[i - 1];
    };
}
