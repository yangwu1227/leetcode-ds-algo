// main.cpp
#include "max_sliding_window.hpp"
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
        {3, {1, 3, -1, -3, 5, 3, 6, 7}},
        {2, {2, 12, 17, 27, 77, 7, 72}},
        {1, {12}}};

    for (auto const &[k, nums] : data)
    {
        std::vector<int> output = maxSlidingWindow(nums, k);
        std::cout << "Input: ";
        printVector(nums);
        std::cout << " | Max sliding window: ";
        printVector(output);
        std::cout << '\n';
    }
    std::cout << std::endl;

    return 0;
}
