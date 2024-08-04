// make_string_great.cpp
#include "make_string_great.hpp"
#include <string>

char swapCase(char character)
{
    if (std::islower(character))
    {
        return std::toupper(character);
    }
    else
    {
        return std::tolower(character);
    }
}

std::string makeStringGreat(const std::string &s)
{
    if (s.length() == 0)
    {
        return s;
    }

    std::string output = "";
    for (const auto &character : s)
    {
        // If the stack is not empty and the top character form a bad pair with the current character
        if (!output.empty() && swapCase(output.back()) == character)
        {
            // Pop the top character and do not push back
            output.pop_back();
        }
        else
        {
            output.push_back(character);
        }
    }

    return output;
}
