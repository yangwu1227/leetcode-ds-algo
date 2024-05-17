// main.cpp
#include "max_length.hpp"
#include "custom_bn_rng.hpp"
#include <vector>
#include <iostream>

int main()
{
    std::vector<std::vector<int>> testNums = {
        generateBinaryVector(9, 0.4),
        generateBinaryVector(12, 0.7),
        generateBinaryVector(7, 0.3)};

    for (const auto &nums : testNums)
    {
        int maxLen = findMaxLength(nums);

        std::cout << "Give the input {";
        for (const auto &num : nums)
        {
            std::cout << num << (&num != &nums.back() ? ", " : "");
        }
        std::cout << "}, the maximum length of a subarray with an equal amount of 1's and 0's is " << maxLen << '\n';
    }
    std::cout << std::endl;

    return 0;
}
