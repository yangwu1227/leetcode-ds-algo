// backspace_compare.hpp
#ifndef BACKSPACE_COMPARE_HPP
#define BACKSPACE_COMPARE_HPP
#include <string>

class CompareStrings
{
public:
    /**
     * @brief Construct a new Compare Strings instance.
     */
    CompareStrings();

    /**
     * @brief Compare two strings that contain backspaces.
     *
     * @param s An std::string
     * @param t An std::string
     * @return bool `true` if the strings are the same, `false` otherwise
     */
    bool compare(const std::string &s, const std::string &t);

private:
    /**
     * @brief A private static member function to build a string containing backspaces.
     *
     * @param string An std::string containing lower case english letters and '#' characters
     * @return std::string A new std::string containing only lower case english characters
     */
    static std::string buildString(const std::string &string);
};

#endif
