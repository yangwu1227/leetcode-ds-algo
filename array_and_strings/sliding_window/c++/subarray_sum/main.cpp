// main.cpp
#include "subarray_sum.h"
#include "custom_rng.h"
#include <vector>
#include <iostream>
#include <boost/range/combine.hpp>

int main()
{
    // Test cases
    std::vector<int> nums1 = generateRandomVector(5, -9, 20);
    std::vector<int> nums2 = generateRandomVector(7, 0, 50);
    std::vector<int> nums3 = {3, -1, 4, 12, -8, 5, 6};
    std::vector<std::vector<int>> testNums = {nums1, nums2, nums3};
    std::vector<int> testK = {4, 2, 3};

    for (const auto &tuple : boost::combine(testNums, testK))
    {
        std::vector<int> nums;
        int k;
        boost::tie(nums, k) = tuple;

        int result = findBestSubarray(nums, k);

        std::cout << "Given the input {";
        for (const auto &value : nums)
        {
            std::cout << value << (&value != &nums.back() ? ", " : "");
        }
        std::cout << "} and k = " << k << ", the largest sum of the a k-subarray is " << result << '\n';
    }
    std::cout << std::endl;

    return 0;
}
