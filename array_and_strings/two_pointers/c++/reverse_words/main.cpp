// main.cpp
#include <iostream>
#include <vector>
#include <string>
#include "reverse_words.hpp"

int main()
{

    std::vector<std::string> testCases = {"Let's take LeetCode contest", "I love python and c++"};

    WordReverser wordReverser;

    // Using loop method to reverse
    for (auto &testCase : testCases)
    {
        std::cout << "Loop: The input '" << testCase;
        wordReverser.reverseWordsLoop(testCase);
        std::cout << "' has been reversed to '" << testCase << "'" << std::endl;
    }

    // Using boost method to reverse it back to original
    for (auto &testCase : testCases)
    {
        std::cout << "Boost: The input '" << testCase;
        std::string result = wordReverser.reverseWordsBoost(testCase);
        std::cout << "' has been restored to '" << result << "'" << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
