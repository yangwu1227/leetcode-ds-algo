// main.cpp
#include "custom_rsg.hpp"
#include "check_if_pangram.hpp"
#include <string>
#include <vector>
#include <iostream>

int main()
{
    std::vector<std::string> testSentences;
    testSentences.reserve(5);
    for (int i = 0; i < 5; ++i)
    {
        // Use emplace_back to construct random std::string directly within the vector
        testSentences.emplace_back(generateRandomString(80));
    }

    for (const auto &sentence : testSentences)
    {
        bool result = checkIfPangram(sentence);
        std::cout << "The input sentence " << sentence << (result ? " is" : " is not") << " a pangram" << '\n';
    }
    std::cout << std::endl;

    return 0;
}
