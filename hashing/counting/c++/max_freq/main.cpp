// main.cpp
#include "max_freq.hpp"
#include <vector>
#include <iostream>

int main()
{
    std::vector<std::vector<int>> testNums = {
        {1, 2, 2, 3, 1, 4},
        {10, 12, 11, 9, 6, 19, 11}};

    for (const auto &nums : testNums)
    {
        int maxCount = maxFreq(nums);
        std::cout << "Give the input {";
        for (const auto &num : nums)
        {
            std::cout << num << (&num != &nums.back() ? ", " : "");
        }
        std::cout << "}, the total count of elements that appear with the highest frequency is " << maxCount << '\n';
    }
    std::cout << std::endl;

    return 0;
}
