// main.cpp
#include "reverse_word_order.hpp"
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> testCases = {"the sky is blue", "  hello world  ", "a good   example"};

    for (auto &testCase : testCases)
    {
        // Using the loop approach
        std::string resultLoop = reverseWordOrder(testCase, false);
        std::cout << "Loop approach: '" << testCase << "' becomes '" << resultLoop << "'" << std::endl;

        // Using Boost's join
        std::string resultBoost = reverseWordOrder(testCase, true);
        std::cout << "Boost approach: '" << testCase << "' becomes '" << resultBoost << "'" << std::endl;
    }

    return 0;
}
