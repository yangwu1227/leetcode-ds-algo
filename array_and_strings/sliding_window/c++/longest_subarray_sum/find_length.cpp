// find_length.cpp
#include "find_length.hpp"
#include <vector>

int findLength(const std::vector<int> &nums, const int &k)
{
    int left = 0, currSum = 0, windowLen = 0;

    for (int right = 0; right < nums.size(); right++)
    {
        // Add the next element on the right to the current sum (i.e. expanding the window)
        currSum += nums[right];

        // Check if the current window (represented by left and right indices) is invalid
        // The constraint metric is 'currSum' and numeric restriction is 'k'
        while (currSum > k)
        {
            // The window is invalid, remove the element the left pointer points at
            currSum -= nums[left];
            // Slide the window towards the right (shrinking the window)
            left++;
        }

        // Update the window size if it is greater than the previous window size
        // Add 1 because we need the length to be left inclusive
        windowLen = std::max(windowLen, right - left + 1);
    }

    return windowLen;
}
