// main.cpp
#include "reverse_letters.h"
#include <string>
#include <iostream>
#include <vector>

int main()
{

    // Test cases
    std::vector<std::string> testCases = {"ab-cd", "a-bC-dEf-ghIj", "Test1ng-Leet=code-Q!"};

    for (auto &testCase : testCases)
    {
        std::cout << "The input string " << testCase;
        reverseLetters(testCase);
        std::cout << " has become " << testCase << std::endl;
    }

    return 0;
}
