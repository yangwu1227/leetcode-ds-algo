// max_ones_k_flips.cpp
#include "max_ones_k_flips.hpp"
#include <vector>

int longestOnes(const std::vector<int> &nums, const int &k)
{
    int currZeroCount = 0, windowLen = 0, left = 0;
    for (int right = 0; right < nums.size(); right++)
    {
        // If the current element the right pointer points to is zero, keep track of it
        if (nums[right] == 0)
        {
            currZeroCount++;
        }
        // Check if the current window has become invalid, i.e. > k zeros that we can no longer flip
        while (currZeroCount > k)
        {
            // Remove element pointed to by the left pointer if it is zero
            if (nums[left] == 0)
            {
                // Removed a zero from the left
                currZeroCount--;
            }
            // Slide the window towards the right
            left++;
        }
        // Check if the current window size if greater than the previous
        windowLen = std::max(windowLen, right - left + 1);
    }
    return windowLen;
}
