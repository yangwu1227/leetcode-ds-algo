// main.cpp
#include "lucky_integer.hpp"
#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::vector<int>> testNums = {
        {2, 2, 3, 4},
        {1, 2, 2, 3, 3, 3},
        {2, 2, 2, 3, 3}};

    for (const auto &nums : testNums)
    {
        int largestLuckyInteger = findLuckyInteger(nums);
        std::cout << "Give the input {";
        for (const auto &num : nums)
        {
            std::cout << num << (&num != &nums.back() ? ", " : "");
        }
        std::cout << "}, the largest lucky number " << (largestLuckyInteger != -1 ? "is " + std::to_string(largestLuckyInteger) : "does not exist") << '\n';
    }
    std::cout << std::endl;

    return 0;
}
