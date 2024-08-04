// make_string_great.hpp
#ifndef MAKE_STRING_GREAT_HPP
#define MAKE_STRING_GREAT_HPP
#include <string>
/**
 * @brief Given a string `s` of lower and upper case English letters. Remove all adjacent characters that one lower case
 * letter followed by an upper case letter, or vice versa.
 *
 * @param s An std::string containing lower case and upper case english characters
 * @return std::string A new std::string that satisfy the requirements of a good string
 */
std::string makeStringGreat(const std::string &s);

#endif
