// main.cpp
#include "minimum_common_integer.h"
#include <vector>
#include <iostream>
#include <boost/range/combine.hpp>

int main() 
{

    std::vector<std::vector<int>> nums1Cases = {{1, 2, 3}, {1, 2, 3, 6}, {1, 2, 3}};
    std::vector<std::vector<int>> nums2Cases = {{2, 4}, {2, 3, 4, 5}, {5, 6, 0}};

    // Use boost::combine for iterating over test_nums and targets simultaneously
    for (const auto &tuple : boost::combine(nums1Cases, nums2Cases))
    {
        // Unpack the tuple, which is a (num1, num2) pair
        std::vector<int> nums1, nums2;
        boost::tie(nums1, nums2) = tuple;

        int result = getCommon(nums1, nums2);

        std::cout << "The inputs {";
        for (const auto &val : nums1) 
        {
            std::cout << val << (&val != &nums1.back() ? ", " : "}");
        }
        std::cout << " and {";
        for (const auto &val : nums2) 
        {
            std::cout << val << (&val != &nums2.back() ? ", " : "}");
        }
        std::cout << " shares " << (result == -1 ? "nothing" : std::to_string(result)) << std::endl;
    }

    return 0;
}
