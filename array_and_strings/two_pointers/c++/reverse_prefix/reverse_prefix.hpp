// reverse_prefix.hpp
#ifndef REVERSE_PREFIX_HPP
#define REVERSE_PREFIX_HPP
#include <string>

/**
 * @brief Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at
 * the index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.
 *
 * @param word 0-indexed string
 * @param ch character
 * @return std::string The resulting string after reversing the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive)
 */
std::string reversePrefix(std::string &word, const char &ch);

#endif
