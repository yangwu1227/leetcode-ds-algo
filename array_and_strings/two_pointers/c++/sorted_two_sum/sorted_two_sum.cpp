// sorted_two_sum.cpp
#include "sorted_two_sum.hpp"

bool checkForTarget(std::vector<int> &nums, int target)
{
    int left_index = 0;
    int right_index = nums.size() - 1;

    while (left_index < right_index)
    {
        // X + Y
        int currentSum = nums[left_index] + nums[right_index];
        if (currentSum == target)
        {
            return true;
        }

        if (currentSum > target)
        {
            // Decrease Y since we are over the target
            right_index--;
        }
        else if (currentSum < target)
        {
            // Increase X since we are under the target
            left_index++;
        }
    }

    // If the while loop finished, then there is no pair that sums to target
    return false;
}
