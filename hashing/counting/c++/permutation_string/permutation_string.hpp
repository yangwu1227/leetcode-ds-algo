// permutation_string.hpp
#ifndef PERMUTATION_STRING_HPP
#define PERMUTATION_STRING_HPP
#include <string>

/**
 * @brief Given two strings `s1` and `s2`, return `True` if `s2` contains a permutation of `s1`.
 *
 * @param s1 A string consisting of lower case english characters
 * @param s2 A string consisting of lower case english characters
 * @return bool `true` if one of `s1`'s permutation is a substring of `s2`, `false` otherwise
 */
bool checkInclusion(const std::string &s1, const std::string &s2);

#endif
