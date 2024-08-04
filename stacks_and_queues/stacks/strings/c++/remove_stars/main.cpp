// main.cpp
#include "remove_stars.hpp"
#include <string>
#include <vector>
#include <iostream>

int main()
{
    std::vector<std::string> testStrings = {"leet**cod*e", "erase*****", "yangwu**python**c++*r"};
    for (const auto &s : testStrings)
    {
        std::string newString = removeStars(s);
        std::cout << "Original string:" << '\n';
        std::cout << s << '\n';
        std::cout << "New string:" << '\n';
        std::cout << (newString.empty() ? "Empty" : newString) << '\n';
        std::cout << '\n';
    }
    return 0;
}
