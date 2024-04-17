// main.cpp
#include "k_radius_avg.hpp"
#include "custom_rng.hpp"
#include <vector>
#include <iostream>
#include <map>

int main()
{
    // Test cases
    std::vector<int> nums1 = generateRandomVector(10, -3, 9);
    std::vector<int> nums2 = generateRandomVector(5, 0, 8);
    std::vector<int> nums3 = generateRandomVector(12, -7, 3);
    std::map<std::vector<int>, int> testCases{{nums1, 3}, {nums2, 2}, {nums3, 4}};

    // Structured bindings
    for (const auto &[nums, k] : testCases)
    {
        std::vector<int> averages = findAverage(nums, k);

        std::cout << "Given the input {";
        for (const auto &value : nums)
        {
            std::cout << value << (&value != &nums.back() ? ", " : "");
        }
        std::cout << "} and k = " << k << ", the k-radius average array is {";
        for (const auto &avg : averages)
        {
            std::cout << avg << (&avg != &averages.back() ? ", " : "");
        }
        std::cout << "}" << '\n';
    }
    std::cout << std::endl;
    return 0;
}
