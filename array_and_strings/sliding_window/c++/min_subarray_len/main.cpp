// main.cpp
#include "min_subarray_len.h"
#include <iostream>
#include <vector>
#include <boost/range/combine.hpp>

int main() 
{
    // Test cases
    std::vector<std::vector<int>> testNums = {{2, 3, 1, 2, 4, 3}, {1, 2, 3, 4, 5}, {1, 4, 4}, {1, 2, 3}};
    std::vector<int> testTargets = {6, 13, 3, 40};

    for (const auto &tuple : boost::combine(testNums, testTargets))
    {
        std::vector<int> nums;
        int target;
        boost::tie(nums, target) = tuple;

        int windowLen = minSubarrayLen(nums, target);

        std::cout << "Given the input ";
        for (const auto &value : nums)
        {
            std::cout << value << (&value != &nums.back() ? ", " : " ");
        }
        std::cout << " and target = " << target << ", the smallest subarray with a sum of >= " << target << " has length " << windowLen << '\n';
    }
    std::cout << std::endl;

    return 0;
}
