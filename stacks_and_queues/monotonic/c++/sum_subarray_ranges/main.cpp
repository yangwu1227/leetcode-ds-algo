// main.cpp
#include "sum_subarray_ranges.hpp"
#include <vector>
#include <iostream>

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
        {4, -2, -3, 4, 1},
        {1, 3, 3},
        {1, 2, 3},
        {12}};

    for (const auto &nums : data)
    {
        long long int output = sumSubarrayRanges(nums);
        std::cout << "Given nums  = ";
        printVector(nums);
        std::cout << ", the sum of ranges of all subarrays is " << output << '\n';
    }
    std::cout << std::endl;

    return 0;
}
