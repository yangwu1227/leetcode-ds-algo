// main.cpp
#include "max_subarray.hpp"
#include <vector>
#include <iostream>
#include <map>

int main()
{
    std::map<std::vector<int>, int> testCases = {
        {{1, 2, 3, 1, 2, 3, 1, 2}, 2},
        {{1, 2, 1, 2, 1, 2, 1, 2}, 1},
        {{5, 5, 5, 5, 5, 5, 5}, 4}};

    for (const auto &[nums, k] : testCases)
    {
        int maxLen = maxSubarrayLength(nums, k);
        std::cout << "Given the input {";
        for (const auto &num : nums)
        {
            std::cout << num << (&num != &nums.back() ? ", " : "");
        }
        std::cout << "}, the longest subarray whose elements have counts less than or equal to " << k << " is " << maxLen << '\n';
    }
    std::cout << std::endl;

    return 0;
}
