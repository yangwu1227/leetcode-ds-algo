// group_anagrams.hpp
#ifndef GROUP_ANAGRAMS_HPP
#define GROUP_ANAGRAMS_HPP
#include <vector>
#include <string>

/**
 * @brief Given an array of strings `strs`, group the anagrams together.
 *
 * @param strs A vector of `std::string`
 * @return std::vector<std::vector<std::string>> Vector of vectors, each of which contains strings that are anagrams of each other
 *
 * @note An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once
 */
std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string> &strs);

#endif
