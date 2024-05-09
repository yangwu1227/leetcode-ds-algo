// main.cpp
#include "subarray_sum.hpp"
#include "custom_rng.hpp"
#include <vector>
#include <iostream>
#include <map>

int main()
{
    // Need std::map since std::vector does not have a built-in hash function
    std::map<std::vector<int>, int> testCases = {
        {generateRandomVector(10, 0, 15), 4},
        {generateRandomVector(5, 3, 12), 3},
        {generateRandomVector(20, 0, 12), 7}};

    for (const auto &[nums, k] : testCases)
    {
        int ans = subarraySum(nums, k);
        std::cout << "Given the input {";
        for (const auto &num : nums)
        {
            std::cout << num << (&num != &nums.back() ? ", " : "");
        }
        std::cout << "}, the number of subarrays that sum to " << k << " is " << ans << '\n';
    }
    std::cout << std::endl;

    return 0;
}
