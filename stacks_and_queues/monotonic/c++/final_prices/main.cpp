// main.cpp
#include "final_prices.hpp"
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
    std::vector<std::vector<int>> priceData = {
        {10, 1, 1, 6},
        {8, 4, 6, 2, 3},
        {1, 2, 3, 4, 5},
        {0, 7, 4, 2, 1}};
    for (auto &prices : priceData)
    {
        std::cout << "Given prices = ";
        printVector(prices);
        std::vector<int> outputHash = FinalPrices::hashApproach(prices);
        // This modifies the vector in place
        FinalPrices::noHashApproach(prices);
        // Compare the two approaches by value
        assert(outputHash == prices);
        std::cout << ", the final prices are ";
        printVector(prices);
        std::cout << '\n';
    }
    std::cout << std::endl;

    return 0;
}
