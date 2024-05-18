// main.cpp
#include "sum_unique.hpp"
#include <vector>
#include <iostream>

int main()
{
    std::vector<std::vector<int>> testNums = {
        {1, 2, 3, 2},
        {1, 1, 1, 1, 1},
        {1, 2, 3, 4, 5},
        {2, 7, 3, 9, 7, 8, 9, 4, 6, 5}};

    for (const auto &nums : testNums)
    {
        int uniqueSum = sumUnique(nums);
        std::cout << "Give the input {";
        for (const auto &num : nums)
        {
            std::cout << num << (&num != &nums.back() ? ", " : "");
        }
        std::cout << "}, the sum of all unique elements is " << uniqueSum << '\n';
    }
    std::cout << std::endl;

    return 0;
}
