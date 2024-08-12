// main.cpp
#include "longest_subarray.hpp"
#include <vector>
#include <iostream>
#include <map>

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
    std::map<int, std::vector<int>> data = {
        {4, {1, 5, 6, 7, 8, 10, 6, 5, 6}},
        {5, {10, 1, 2, 4, 7, 2}},
        {3, {8, 2, 4, 7}}};

    for (auto const &[limit, nums] : data)
    {
        int windowSize = longestSubarray(nums, limit);
        std::cout << "Given nums = ";
        printVector(nums);
        std::cout << " and limit = " << limit << " the longest subarray that satisfies the condition has " << windowSize << " elements\n";
    }
    std::cout << std::endl;

    return 0;
}
