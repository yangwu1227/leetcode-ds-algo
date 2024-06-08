// word_pattern.hpp
#ifndef WORD_PATTERN_HPP
#define WORD_PATTERN_HPP
#include <string>

/**
 * @brief Given a `pattern` and a string `s`, find if `s` follows the `pattern`.
 *
 * @param pattern A pattern consisting of lower case english characters
 * @param s A string consisting of lower case english characters and single white spaces
 * @param boost Using boost algorithm to split `s` if `true`, otherwise use `std::istringstream`
 * 
 * @return bool `true` if `s` follows `pattern`, otherwise `false`
 */
bool wordPattern(const std::string &pattern, const std::string &s, bool boost);

#endif