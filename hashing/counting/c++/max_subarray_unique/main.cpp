// main.cpp
#include "max_subarray_unique.hpp"
#include <vector>
#include <iostream>

int main()
{
    std::vector<std::vector<int>> testNums = {
        {4, 2, 4, 5, 6},
        {5, 2, 1, 2, 5, 2, 1, 2, 5},
        {9, 10, 8, 8, 7, 6, 3, 12, 34, 3, 4, 8, 4, 9, 24, 6}};

    for (const auto &nums : testNums)
    {
        int maxSum = maxSubarrayUnique(nums);
        std::cout << "Give the input {";
        for (const auto &num : nums)
        {
            std::cout << num << (&num != &nums.back() ? ", " : "");
        }
        std::cout << "}, the maximum sum of a unique subarray is " << maxSum << '\n';
    }
    std::cout << std::endl;

    return 0;
}
