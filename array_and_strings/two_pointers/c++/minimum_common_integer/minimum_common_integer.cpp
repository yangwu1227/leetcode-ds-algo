// minimum_common_integer.cpp
#include "minimum_common_integer.h"
#include <vector>

int getCommon(const std::vector<int> &nums1, const std::vector<int> &nums2) 
{
    int i = 0, j = 0;

    // The loop finishes once one of the two arrays is exhausted
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] == nums2[j]) 
        {
            return nums1[i];
        } else if (nums1[i] < nums2[j])
        {
            // If element j in array 2 is greater than element i in array 1
            // Increment i (the smaller index) since j can only point to a larger value
            i++;
        } else if (nums2[j] < nums1[i])
        {
            // If element i in array 1 is greater than element j in array 2
            // Increment j (the smaller index) since i can only point to a larger value
            j++;
        }
    }

    // If while completes without returning, then -1
    return -1;
}
