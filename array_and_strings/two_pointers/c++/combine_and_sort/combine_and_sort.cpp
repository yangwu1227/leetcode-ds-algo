// combine_and_sort.cpp
#include "combine_and_sort.h"
#include <vector>

std::vector<int> combine(const std::vector<int> &arr1, const std::vector<int> &arr2)
{

    int arr1Index = 0, arr2Index = 0;
    int arr1N = arr1.size(), arr2M = arr2.size();

    std::vector<int> ans;
    // Request vector capacity to be at least (n + m), so push back
    ans.reserve(arr1N + arr2M);

    // Once this while loop finished, at least one array is exhausted
    while (arr1Index < arr1N & arr2Index < arr2M)
    {

        if (arr1[arr1Index] < arr2[arr2Index])
        {
            // Element from array 1 is smaller, push back and increment
            ans.push_back(arr1[arr1Index]);
            arr1Index++;
        }
        else if ((arr2[arr2Index] < arr1[arr1Index]))
        {
            // Element from array 2 is smaller, push back and increment
            ans.push_back(arr2[arr2Index]);
            arr2Index++;
        }
        else
        {
            // If ==, push back and increment both
            ans.push_back(arr1[arr1Index]);
            ans.push_back(arr2[arr2Index]);
            arr1Index++;
            arr2Index++;
        }
    }

    // Ensure arr1 is exhausted
    while (arr1Index < arr1N)
    {
        ans.push_back(arr1[arr1Index]);
        arr1Index++;
    }

    // Ensure arr2 is exhausted
    while (arr2Index < arr2M)
    {
        ans.push_back(arr2[arr2Index]);
        arr2Index++;
    }

    return ans;
}
