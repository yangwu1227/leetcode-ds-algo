// main.cpp
#include "move_zeros.hpp"
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> nums1 = {0, 1, 0};
    std::vector<int> nums2 = {0, 1, 0, 3, 12};

    /* ----------------------------- First test case ---------------------------- */

    std::cout << "The input {";
    for (const auto &num : nums1)
    {
        std::cout << num << (&num != &nums1.back() ? ", " : "");
    }
    std::cout << "} becomes ";
    moveZeros(nums1);
    std::cout << "{";
    for (const auto &num : nums1)
    {
        std::cout << num << (&num != &nums1.back() ? ", " : "");
    }
    std::cout << "}" << std::endl;

    /* ---------------------------- Second test case ---------------------------- */

    std::cout << "The input {";
    for (const auto &num : nums2)
    {
        std::cout << num << (&num != &nums2.back() ? ", " : "");
    }
    std::cout << "} becomes ";
    moveZeros(nums2);
    std::cout << "{";
    for (const auto &num : nums2)
    {
        std::cout << num << (&num != &nums2.back() ? ", " : "");
    }
    std::cout << "}" << std::endl;

    return 0;
}
