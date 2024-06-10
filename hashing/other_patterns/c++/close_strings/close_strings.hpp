// close_strings.hpp
#ifndef CLOSE_STRINGS_HPP
#define CLOSE_STRINGS_HPP
#include <string>

/**
 * @brief Check if two strings are considered close. Two strings are close if one can be transformed into the other using the following operations:
 *
 *  - Swap any two existing characters in the string. Example: 'abcde' -> 'aecdb'
 *  - Transform every occurrence of one character into another character and vice versa. Example: 'aacabb' -> 'bbcbaa' (all 'a's are transformed into 'b's and all 'b's into 'a's)
 *
 * Both operations can be used on either string as many times as necessary.
 *
 * @param first An std::string consisting of lower case english characters
 * @param second An std::string consisting of lower case english characters
 * @return bool `true` if `first` and `second` are close, otherwise `false`
 */
bool closeStrings(const std::string &first, const std::string &second);

#endif