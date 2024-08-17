// main.cpp
#include "sum_subarray_mins.hpp"
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
    std::vector<std::vector<int>> data = {{3, 1, 2, 4}, {11, 81, 94, 43, 3}};

    for (auto const &x : data)
    {
        int sumMins = sumSubarrayMins(x);
        std::cout << "Given array = ";
        printVector(x);
        std::cout << ", the the sum of all subarray minimums is " << sumMins << '\n';
    }
    std::cout << std::endl;

    return 0;
}
