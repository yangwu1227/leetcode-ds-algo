// remove_stars.cpp
#include "remove_stars.hpp"
#include <string>

std::string removeStars(const std::string &s)
{
    if (s.length() == 1)
    {
        return s;
    }

    std::string output = "";
    for (const auto &character : s)
    {
        if (!output.empty() && character == '*')
        {
            output.pop_back();
        }
        else
        {
            output.push_back(character);
        }
    }
    return output;
}
