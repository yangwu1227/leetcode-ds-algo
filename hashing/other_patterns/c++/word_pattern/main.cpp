// main.cpp
#include "word_pattern.hpp"
#include <string>
#include <unordered_map>
#include <cassert>
#include <iostream>

int main()
{
    std::unordered_map<std::string, std::string> testCases = {
        {"abba", "dog cat cat dog"},
        {"aaaa", "dog cat cat dog"},
        {"aaa", "aa aa aa aa"}};

    for (const auto &[pattern, s] : testCases)
    {
        bool followsPatternBoost = wordPattern(pattern, s, true);
        bool followsPattern = wordPattern(pattern, s, false);
        assert(followsPattern == followsPatternBoost);
        std::cout << "Given s = '" << s << "' and pattern = '" << pattern << "', 's' " << (followsPattern ? "follows" : "does not follow") << " 'pattern'\n";
    }
    std::cout << std::endl;

    return 0;
}