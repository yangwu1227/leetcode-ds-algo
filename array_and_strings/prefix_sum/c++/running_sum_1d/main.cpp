// main.cpp
#include "running_sum_1d.hpp"
#include <vector>
#include <iostream>

int main()
{
    std::vector<std::vector<int>> testNums = {{3, 1, 2, 10, 1}, {9, 7, 12, 2, 7}};

    for (auto &nums : testNums)
    {
        std::cout << "Given the input {";
        for (const auto &value : nums)
        {
            std::cout << value << (&value != &nums.back() ? ", " : "");
        }
        std::cout << "}, the running sum is ";

        // Modify in place
        runningSum(nums);

        std::cout << "{";
        for (const auto &value : nums)
        {
            std::cout << value << (&value != &nums.back() ? ", " : "");
        };
        std::cout << "}" << '\n';
    }
    std::cout << std::endl;

    return 0;
}
