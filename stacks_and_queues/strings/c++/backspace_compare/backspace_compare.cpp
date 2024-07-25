// backspace_compare.cpp
#include "backspace_compare.hpp"
#include <string>

CompareStrings::CompareStrings() {}

std::string CompareStrings::buildString(const std::string &string)
{
    std::string output;
    output.reserve(string.length());
    for (const auto &character : string)
    {
        // If '#' and the stack is not empty, pop from the top of the stack
        if (!output.empty() && character == '#')
        {
            output.pop_back();
        }
        else if (character != '#')
        {
            output.push_back(character);
        }
    }
    return output;
}

bool CompareStrings::compare(const std::string &s, const std::string &t)
{
    if (s.length() == 1 && t.length() == 1)
    {
        return s == t;
    }
    return this->buildString(s) == this->buildString(t);
}
