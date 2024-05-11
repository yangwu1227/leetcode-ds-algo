// main.cpp
#include "subarray_odd.hpp"
#include <vector>
#include <iostream>
#include <map>

int main()
{
    std::map<std::vector<int>, int> testNums = {
        {{1, 1, 2, 1, 1}, 3},
        {{2, 2, 2, 1, 2, 2, 1, 2, 2, 2}, 2},
        {{3, 2, 4, 5, 6}, 2}};

    for (const auto &[nums, k] : testNums)
    {
        int ans = subarrayOdd(nums, k);
        std::cout << "Given the input {";
        for (const auto &num : nums)
        {
            std::cout << num << (&num != &nums.back() ? ", " : "");
        }
        std::cout << "} and k = " << k << ", there are " << ans << " subarrays with exactly " << k << " odd numbers" << '\n';
    }
    std::cout << std::endl;

    return 0;
}
