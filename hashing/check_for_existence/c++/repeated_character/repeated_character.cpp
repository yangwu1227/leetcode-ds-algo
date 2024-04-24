// repeated_character.cpp
#include "repeated_character.hpp"
#include <string>
#include <unordered_map>
#include <unordered_set>

// Definition for the map implementation
char Solution::repeatedCharacterMap(const std::string &s)
{
    std::unordered_map<char, int> counter;
    for (const auto &character : s)
    {
        counter[character]++;

        // Once the count exceeds 1, return
        if (counter[character] > 1)
        {
            return character;
        }
    }

    // Never gets here if `s` is guaranteed a solution
    return ' ';
}

// Definition for the set implementation
char Solution::repeatedCharacterSet(const std::string &s)
{
    std::unordered_set<char> seen;
    for (const auto &character : s)
    {
        // We can also use contains, which is a C++ addition
        // If find returns the iterator pointing to something other than .end(), we found a letter that has appeared once already
        if (seen.find(character) != seen.end())
        {
            return character;
        }

        // If not found, add it to the set, costing O(1)
        seen.insert(character);
    }

    return ' ';
}
