// main.cpp
#include "asteroid.hpp"
#include <vector>
#include <iostream>

void printVector(const std::vector<int> &vector)
{
    std::cout << "{";
    for (const auto &element : vector)
    {
        std::cout << element << (&element != &vector.back() ? ", " : "");
    }
    std::cout << "}";
}

int main()
{
    std::vector<std::vector<int>> testData = {
        {-2, 1, 1, -1},
        {10, 2, -5},
        {-2, -2, -2, -1},
        {8, -8}};

    for (const auto &data : testData)
    {
        std::vector<int> processedData = asteroid(data);
        std::cout << "Given data = ";
        printVector(data);
        std::cout << ", the processed data is ";
        printVector(processedData);
        std::cout << '\n';
    }
    std::cout << std::endl;

    return 0;
}
