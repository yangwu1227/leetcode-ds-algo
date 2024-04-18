// main.cpp
#include "pivot_index.hpp"
#include <vector>
#include <iostream>
#include <string>

int main()
{
    std::vector<int> nums1 = {1, 7, 3, 6, 5, 6};
    std::vector<int> nums2 = {1, 2, 3};
    std::vector<int> nums3 = {2, 1, -1};
    std::vector<std::vector<int>> testNums = {nums1, nums2, nums3};

    for (const auto &nums : testNums)
    {
        int pivot = pivotIndex(nums);

        std::cout << "Given the input {";
        for (const auto &value : nums)
        {
            std::cout << value << (&value != &nums.back() ? ", " : "");
        }
        std::cout << "}, the pivot index ";
        std::cout << (pivot == -1 ? "does not exist." : "is " + std::to_string(pivot) + ".") << '\n';
    }
    std::cout << std::endl;

    return 0;
}
