// main.cpp
#include "max_ones_single_flip.hpp"
#include <iostream>
#include <string>
#include <vector>

int main()
{
    // Test cases
    std::vector<std::string> testCases = {"11001011", "1000011", "0101010011101"};

    for (const auto &binary_string : testCases)
    {
        int windowLen = findLength(binary_string);

        std::cout << "The input " << binary_string << " has a longest substring of " << windowLen << " consecutive 1's if we flip one 0" << '\n';
    }
    std::cout << std::endl;

    return 0;
}
