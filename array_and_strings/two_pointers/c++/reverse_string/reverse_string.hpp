// reverse_string.hpp
#ifndef REVERSE_STRING_HPP
#define REVERSE_STRING_HPP

#include <vector>

/**
 * @brief Given a list of characters, reverse the order of the characters in-place.
 *
 * @param s List of characters.
 * @return void
 * @note Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
 * @note You may assume all the characters consist of printable ascii characters.
 * @note The input vector will always have a length in the range [1, 10^5].
 */
void reverseString(std::vector<char> &s);

#endif
