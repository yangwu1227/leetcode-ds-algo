// main.cpp
#include "split_array.hpp"
#include <vector>
#include <iostream>

int main()
{
    std::vector<std::vector<int>> testNums = {{10, 4, -8, 7}, {2, 3, 1, 0}};

    for (const auto &nums : testNums)
    {
        int validSplits = splitArray(nums);

        std::cout << "Given the input {";
        for (const auto &value : nums)
        {
            std::cout << value << (&value != &nums.back() ? ", " : "");
        }
        std::cout << "}, the there are " << validSplits << " number of splits that satisfies the criteria" << '\n';
    }
    std::cout << std::endl;

    return 0;
}
