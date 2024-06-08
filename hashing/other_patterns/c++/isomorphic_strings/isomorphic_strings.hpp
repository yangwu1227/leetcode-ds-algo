// isomorphic_string.hpp
#ifndef ISOMORPHIC_STRINGS_HPP
#define ISOMORPHIC_STRINGS_HPP
#include <string>

/**
 * @brief Given two strings `s` and `t`, determine if they are isomorphic. Two strings `s` and `t` are isomorphic if the characters in `s` can be replaced to get `t`.
 *
 * @param s A string containing valid ASCII characters
 * @param t A string containing valid ASCII characters
 * @return bool `true` if `s` and `t` are isomophic, other wise `false`
 *
 * @note All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same
    character, but a character may map to itself.
 */
bool isomorphic(const std::string &s, const std::string &t);

#endif