// main.cpp
#include "max_ones_k_flips.hpp"
#include "custom_bn_rng.hpp"
#include <vector>
#include <iostream>
#include <boost/range/combine.hpp>

int main()
{
    // Test cases
    std::vector<std::vector<int>> testNums = {
        generateBinaryVector(10, 0.5),
        generateBinaryVector(7, 0.3),
        generateBinaryVector(14, 0.4)};
    std::vector<int> testK = {3, 4, 2};

    for (const auto &tuple : boost::combine(testNums, testK))
    {
        std::vector<int> nums;
        int k;
        boost::tie(nums, k) = tuple;

        int result = longestOnes(nums, k);

        std::cout << "Given input {";
        for (const auto &value : nums)
        {
            std::cout << value << (&value != &nums.back() ? ", " : "");
        }
        std::cout << "} and k = " << k << ", the longest consecutive subarray of 1's has length " << result << '\n';
    }
    std::cout << std::endl;

    return 0;
}
