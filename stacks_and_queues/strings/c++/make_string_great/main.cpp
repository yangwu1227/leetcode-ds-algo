// main.cpp
#include "make_string_great.hpp"
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> testStrings = {"leEeetcode", "abBAcC", "AdG"};
    for (const auto &s : testStrings)
    {
        std::string newString = makeStringGreat(s);
        std::cout << "Original string:" << '\n';
        std::cout << s << '\n';
        std::cout << "New string:" << '\n';
        std::cout << (newString.empty() ? "Empty" : newString) << '\n';
        std::cout << '\n';
    }
    std::cout << std::endl;

    return 0;
}
