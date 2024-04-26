// check_if_pangram.hpp
#ifndef CHECK_IF_PANGRAM_HPP
#define CHECK_IF_PANGRAM_HPP
#include <string>

/**
 * @brief A pangram is a sentence where every letter of the English alphabet appears at least once. Given a string sentence, return true if
 * sentence is a pangram, or false otherwise.
 *
 * @param sentence A sentence containing only lowercase English letters
 * @return bool true if a pangram, otherwise false
 */
bool checkIfPangram(const std::string &sentence);

#endif
