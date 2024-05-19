// main.cpp
#include "unique_count.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<std::vector<int>> testNums = {
        {1, 2, 2, 1, 1, 3},
        {1, 2},
        {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0}};

    for (const auto &nums : testNums)
    {
        bool allCountsUnique = uniqueCount(nums);
        std::cout << "Given the input {";
        for (const auto &num : nums)
        {
            std::cout << num << (&num != &nums.back() ? ", " : "");
        }
        std::cout << "}," << (allCountsUnique ? "" : " not") << " all elements have unique counts" << '\n';
    }
    std::cout << std::endl;

    return 0;
}
