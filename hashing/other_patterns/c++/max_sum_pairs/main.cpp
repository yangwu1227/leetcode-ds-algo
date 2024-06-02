// main.cpp
#include "max_sum_pairs.hpp"
#include <vector>
#include <iostream>
#include <string>

int main()
{
    std::vector<std::vector<int>> testNums = {
        {18, 43, 36, 13, 7},
        {10, 12, 19, 14},
        {9, 2, 2, 5},
        {279, 169, 463, 252, 94, 455, 423, 315, 288, 64, 494, 337, 409, 283, 283, 477, 248, 8, 89, 166, 188, 186, 128}};

    for (const auto &nums : testNums)
    {
        int ans = maxSum(nums);
        std::cout << "Given the input {";
        for (const auto &num : nums)
        {
            std::cout << num << (&num != &nums.back() ? ", " : "");
        }
        std::cout << "}, the maximum sum of equivalent pairs " << (ans != -1 ? "is " + std::to_string(ans) : "does not exist") << '\n';
    }
    std::cout << std::endl;

    return 0;
}