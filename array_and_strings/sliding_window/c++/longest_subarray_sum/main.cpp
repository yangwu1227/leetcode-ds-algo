// main.cpp
#include "find_length.h"
#include <iostream>
#include <vector>
#include <boost/range/combine.hpp>

int main()
{
    // Test cases
    std::vector<std::vector<int>> testNums = {{3, 1, 2, 7, 4, 2, 1, 1, 5}, {3, 2, 8, 7, 3, 9}};
    std::vector<int> testK = {8, 5};

    for (const auto &tuple : boost::combine(testNums, testK))
    {
        // Unpack
        std::vector<int> nums;
        int k;
        boost::tie(nums, k) = tuple;

        int windowLen = findLength(nums, k);

        std::cout << "Given the input {";
        for (const auto &value : nums)
        {
            std::cout << value << (&value != &nums.back() ? ", " : "");
        }
        std::cout << "} and constraint " << k << ", the longest subarray has length " << windowLen << std::endl;
    }

    return 0;
}
