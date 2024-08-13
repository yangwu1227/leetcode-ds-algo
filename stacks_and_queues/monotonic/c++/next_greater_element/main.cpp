// main.cpp
#include "next_greater_element.hpp"
#include <map>
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
    std::map<std::vector<int>, std::vector<int>> data = {
        {{1, 3, 5, 7, 9}, {9, 7, 5, 3, 1}},
        {{4, 1, 2}, {1, 3, 4, 2}},
        {{2, 4}, {1, 2, 3, 4}},
        {{2, 3, 5, 1, 0, 7, 3}, {5, 7, 1}}};

    for (auto const &[nums_1, nums_2] : data)
    {
        std::vector<int> output = nextGreaterElement(nums_1, nums_2);
        std::cout << "Given nums 1 = ";
        printVector(nums_1);
        std::cout << " and nums 2 = ";
        printVector(nums_2);
        std::cout << ", the output is ";
        printVector(output);
        std::cout << '\n';
    }
    std::cout << std::endl;

    return 0;
}
