// remove_duplicates.cpp
#include "remove_duplicates.hpp"
#include <string>

std::string removeDuplicates(const std::string &s)
{
    if (s.length() == 1)
    {
        return s;
    }

    std::string output;
    output.reserve(s.length());
    for (const auto &character : s)
    {
        // If the stack is not empty and the top of the stack is the same as the current character, adjacent duplicates detected
        if (!output.empty() && output.back() == character)
        {
            output.pop_back();
            continue;
        }

        // If stack is empty or the top of the stack is not the same as the current character, push the current character
        output.push_back(character);
    }

    return output;
}
