// main.cpp
#include "sort_string.hpp"
#include <string>
#include <unordered_map>
#include <iostream>

int main()
{
    std::unordered_map<std::string, std::string> testCases = {
        {"cba", "abcd"},
        {"bcafg", "abcd"}};

    for (const auto &[order, s] : testCases)
    {
        std::string permString = sortString(order, s);
        std::cout << "Given order = '" << order << "', the permuated version of s = '" << s << "' is '" << permString << "'\n";
    }
    std::cout << std::endl;

    return 0;
}