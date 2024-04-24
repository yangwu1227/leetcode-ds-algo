// main.cpp
#include "repeated_character.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <cassert>

int main()
{
    std::vector<std::string> testStrings = {"abcdd", "abccbaacz", "machinelearningandstatistics"};
    for (const auto &s : testStrings)
    {
        char charMap = Solution::repeatedCharacterMap(s);
        char charSet = Solution::repeatedCharacterSet(s);
        assert(charMap == charSet);

        std::cout << "Give the input string " << s << ", the first letter to appear twice is " << charSet << '\n';
    }
    std::cout << std::endl;
    return 0;
}
