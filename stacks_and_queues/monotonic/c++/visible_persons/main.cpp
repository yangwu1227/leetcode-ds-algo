// main.cpp
#include "visible_persons.hpp"
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
        {9, 10, 7, 2, 12, 13, 17},
        {10, 6, 8, 5, 11, 9},
        {12}};
    for (const auto &heights : data)
    {
        std::vector<int> output = visiblePersons(heights);
        std::cout << "Given heights = ";
        printVector(heights);
        std::cout << ", the visibility array is ";
        printVector(output);
        std::cout << '\n';
    }
    std::cout << std::endl;

    return 0;
}
