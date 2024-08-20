// main.cpp
#include "num_valid_subarrays.hpp"
#include <vector>
#include <iostream>
#include <cassert>

// Assume that T has overloaded <<, which is true for all primitive types such as int, double, char, etc.
template <typename T>
void printVector(const std::vector<T> &vector)
{
    std::cout << "{";
    for (auto const &element : vector)
    {
        std::cout << element << (&element != &vector.back() ? ", " : "");
    }
    std::cout << "}";
}

int main()
{
    std::vector<std::vector<int>> data = {
        {1, 4, 2, 5, 3},
        {8, 7, 4, 3, 1},
        {2, 2, 2},
        {1, 7, 9, 12},
        {4, 9, 6, 12, 17, 8, 72, 27}};

    for (auto const &nums : data)
    {
        int leftToRightCounts = NumValidSubarray::leftToRight(nums);
        int rightToLeftCounts = NumValidSubarray::rightToLeft(nums);
        assert(leftToRightCounts == rightToLeftCounts);
        std::cout << "Given nums = ";
        printVector(nums);
        std::cout << ", the number of valid subarrays is " << rightToLeftCounts << '\n';
    }
    std::cout << std::endl;

    return 0;
}
