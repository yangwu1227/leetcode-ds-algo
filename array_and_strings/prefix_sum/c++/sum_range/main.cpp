// main.cpp
#include "custom_rng.hpp"
#include "sum_range.hpp"
#include <vector>
#include <iostream>
#include <map>

int main()
{
    std::vector<int> nums = generateRandomVector(17, -10, 10);
    std::map<int, int> indices = {{1, 5}, {7, 15}, {0, 9}, {13, 16}, {3, 11}};

    NumArray numArray(nums);
    std::cout << "Give the input {";
    for (const auto &value : numArray.nums)
    {
        std::cout << value << (&value != &numArray.nums.back() ? ", " : "");
    }
    std::cout << "}:" << '\n';
    for (const auto &[left, right] : indices)
    {
        int subArraySum = numArray.sumRange(left, right);
        std::cout << "The sum of subarray (" << left << ", " << right << ") is " << subArraySum << '\n';
    }
    std::cout << std::endl;

    return 0;
}
