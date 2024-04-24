// repeated_character.hpp
#ifndef REPEATED_CHARACTER_HPP
#define REPEATED_CHARACTER_HPP
#include <string>

class Solution
{
public:
    /**
     * @brief Given a string `s` consisting of lowercase English letters, return the first letter to appear twice. This implementation uses `std::unordered_map`.
     *
     * @param s A string containing lowercase english characters
     * @return char The fist character to appear twice
     */
    static char repeatedCharacterMap(const std::string &s);

    /**
     * @brief Given a string `s` consisting of lowercase English letters, return the first letter to appear twice. This implementation uses `std::unordered_set`.
     *
     * @param s A string containing lowercase english characters
     * @return char The fist character to appear twice
     */
    static char repeatedCharacterSet(const std::string &s);
};

#endif
