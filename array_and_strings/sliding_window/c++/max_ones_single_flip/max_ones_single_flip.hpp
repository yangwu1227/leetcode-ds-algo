// binary_string.hpp
#ifndef BINARY_STRING_HPP
#define BINARY_STRING_HPP
#include <string>

/**
 * @brief Given a binary string s, return the length of the longest contiguous substring containing only 1's. For example, 
 * given s = "1101100111", the answer is 5. If you perform the flip at index 2, the string becomes 1111100111.
 * 
 * @param s A binary string containing only "0" and "1".
 * @return int The length of the longest contiguous substring containing only 1's.
 * 
 * @note The input string is guaranteed to contain only "0" and "1".
 */
int findLength(const std::string &s);

#endif
