// main.cpp
#include "subarray_sum_binary.hpp"
#include "custom_bn_rng.hpp"
#include <vector>
#include <map>
#include <iostream>

int main()
{
    std::map<std::vector<int>, int> testCases = {
        {generateBinaryVector(16, 0.8), 7},
        {generateBinaryVector(7, 0.2), 5},
        {generateBinaryVector(8, 0.3), 3},
        {generateBinaryVector(14, 0.6), 8},
        {generateBinaryVector(12, 0.7), 4}};

    for (const auto &[nums, k] : testCases)
    {
        int numSubarray = subarraySumBinary(nums, k);
        std::cout << "Given the input {";
        for (const auto &num : nums)
        {
            std::cout << num << (&num != &nums.back() ? ", " : "");
        }
        std::cout << "}, there are " << numSubarray << " subarrays with sum k = " << k << '\n';
    }
    std::cout << std::endl;

    return 0;
}
