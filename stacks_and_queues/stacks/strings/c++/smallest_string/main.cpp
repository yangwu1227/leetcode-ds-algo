// main.cpp
#include "smallest_string.hpp"
#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> testStrings = {"bdda", "zza", "a", "yangwupython"};
    for (const auto &s : testStrings)
    {
        std::cout << "Original string: " << s << '\n';
        std::string newString = smallestString(s);
        std::cout << "New string: " << newString << '\n';
        std::cout << '\n';
    }
    std::cout << std::endl;

    return 0;
}
