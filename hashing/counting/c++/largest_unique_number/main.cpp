// main.cpp
#include "largest_unique_number.hpp"
#include <vector>
#include <iostream>
#include <string>

int main()
{
    std::vector<std::vector<int>> testNums = {
        {5, 7, 3, 9, 4, 9, 8, 3, 1},
        {9, 9, 8, 8}};

    for (const auto &nums : testNums)
    {
        int maxInt = largestUniqueNumber(nums);
        std::cout << "Given the input {";
        for (const auto &num : nums)
        {
            std::cout << num << (&num != &nums.back() ? ", " : "");
        }
        std::cout << "}, the largest unique number " << (maxInt == -1 ? "does not exist" : "is " + std::to_string(maxInt)) << '\n';
    }
    std::cout << std::endl;

    return 0;
}
