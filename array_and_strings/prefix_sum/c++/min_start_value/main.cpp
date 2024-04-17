// main.cpp
#include "min_start_value.hpp"
#include "custom_rng.hpp"
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> nums1 = generateRandomVector(10, -3, 7);
    std::vector<int> nums2 = generateRandomVector(7, -2, 5);
    std::vector<int> nums3 = generateRandomVector(5, 3, 17);
    std::vector<std::vector<int>> testNums = {nums1, nums2, nums3};

    for (const auto &nums : testNums)
    {
        int ans = minStartValue(nums);

        std::cout << "Give the input {";
        for (const auto &value : nums)
        {
            std::cout << value << (&value != &nums.back() ? ", " : "");
        }
        std::cout << "}, the minimum start values is " << ans << '\n';
    }
    std::cout << std::endl;

    return 0;
}
