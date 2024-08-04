// main.cpp
#include "valid_parentheses.hpp"
#include <vector>
#include <string>
#include <iostream>

int main()
{
    std::vector<std::string> testStrings = {"()", "()[]{}", "(]", "]", "){"};
    for (const auto &s : testStrings)
    {
        bool isValid = validParentheses(s);
        std::cout << "The string " << s << (isValid ? " is " : " is not ") << "valid" << '\n';
    }
    std::cout << std::endl;

    return 0;
}
