// main.cpp
#include "num_identical_pairs.hpp"
#include <vector>
#include <iostream>

int main()
{
    std::vector<std::vector<int>> testNums = {
        {1, 2, 3, 1, 1, 3},
        {1, 1, 1, 1},
        {0, 9, 7, 3, 2}};

    for (const auto &nums : testNums)
    {
        int numPairs = numIdenticalPairs(nums);
        std::cout << "Given the input {";
        for (const auto &num : nums)
        {
            std::cout << num << (&num != &nums.back() ? ", " : "");
        }
        std::cout << "}, there are " << numPairs << " valid pairs" << '\n';
    }
    std::cout << std::endl;

    return 0;
}
