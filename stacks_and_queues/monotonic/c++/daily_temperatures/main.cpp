// main.cpp
#include "daily_temperatures.hpp"
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
    std::vector<std::vector<int>> temperaturesData = {
        {73, 74, 75, 71, 69, 72, 76, 73},
        {30, 40, 50, 60},
        {37}};

    for (auto const &temperatures : temperaturesData)
    {
        std::vector<int> output = dailyTemperatures(temperatures);
        std::cout << "Temperatures: ";
        printVector(temperatures);
        std::cout << " | Days until next warmer: ";
        printVector(output);
        std::cout << '\n';
    }
    std::cout << std::endl;

    return 0;
}
