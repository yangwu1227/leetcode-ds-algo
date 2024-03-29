// main.cpp
#include "sorted_squares.h"
#include <vector>
#include <iostream>

int main()
{

    std::vector<int> num1 = {-7, -3, 2, 3, 11};
    std::vector<int> num2 = {-4, -1, 0, 3, 10};

    // Vector of vectors
    std::vector<std::vector<int>> testCases = {num1, num2};

    for (const auto &testCase : testCases)
    {
        std::vector<int> result = sortedSquares(testCase);

        std::cout << "The input ";
        for (const auto &originalValue : testCase)
        {
            std::cout << originalValue << (&originalValue != &testCase.back() ? ", " : "");
        }
        std::cout << "} becomes ";

        std::cout << "{";
        for (const auto &squaredValue : result)
        {
            std::cout << squaredValue << (&squaredValue != &result.back() ? ", " : "");
        }
        std::cout << "}" << std::endl;
    }

    return 0;
}
