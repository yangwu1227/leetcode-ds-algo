// main.cpp
#include <vector>
#include <string>
#include <iostream>
#include "reverse_string.hpp"

int main()
{
        // Test cases (single quote for character)
        std::vector<char> s1{'h', 'e', 'l', 'l', 'o'};
        std::vector<char> s2{'H', 'a', 'n', 'n', 'a', 'h'};
        std::vector<char> s3{'y', 'a', 'n', 'g', 'w', 'u'};

        std::vector<std::vector<char>> testCases = {s1, s2, s3};

        // Reference but not const
        for (auto &testCase : testCases)
        {
                // Before reversing
                std::cout << "Before reversing: {";
                for (const auto &character : testCase)
                {
                        std::cout << character << (&character != &testCase.back() ? ", " : "");
                }
                std::cout << "}" << std::endl;

                // Reverse in place
                reverseString(testCase);

                // After reversion
                std::cout << "After reversing: {";
                for (const auto &character : testCase)
                {
                        std::cout << character << (&character != &testCase.back() ? ", " : "");
                }
                std::cout << "}" << std::endl;
        }

        return 0;
}
