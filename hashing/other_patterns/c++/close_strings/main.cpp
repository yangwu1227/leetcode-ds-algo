// main.cpp
#include "close_strings.hpp"
#include <unordered_map>
#include <iostream>
#include <string>

int main()
{
    std::unordered_map<std::string, std::string> testCases = {
        {"abc", "bca"},
        {"a", "aa"},
        {"cabbba", "abbccc"},
        {"yangwucpp", "pythoncpp"}};

    for (const auto &[first, second] : testCases)
    {
        bool close = closeStrings(first, second);
        std::cout << "Given '" << first << "' and '" << second << "', the two strings are" << (close ? " " : " not ") << "close to each other'\n";
    }
    std::cout << std::endl;

    return 0;
}