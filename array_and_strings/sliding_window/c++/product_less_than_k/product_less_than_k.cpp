// product_less_than_k.cpp
#include "product_less_than_k.hpp"
#include <vector>

int numSubarraysProductLessThanK(const std::vector<int> &nums, const int &k)
{
    // If k <= 1, then there is no valid window
    if (k <= 1)
    {
        return 0;
    }

    // Initialization
    int currProduct = 1, left = 0, numSubarrays = 0;

    for (int right = 0; right < nums.size(); right++)
    {
        // Product of all elements in the current window
        currProduct *= nums[right];

        // Check if window becomes invalid, i.e. currProduct exceeds or equals to k
        while (currProduct >= k)
        {
            // Divide the product by the element the left pointer points to
            currProduct /= nums[left];
            // Slide the window towards the right
            left++;
        }

        // Add the total number of subarrays in the current window to the total
        // This is because given the current window (left, right), there are (right - left + 1) subarrays
        numSubarrays += right - left + 1;
    }

    return numSubarrays;
}
