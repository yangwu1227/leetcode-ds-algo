// split_words.hpp
#ifndef SPLIT_WORDS_HPP
#define SPLIT_WORDS_HPP
#include <vector>
#include <string>

/**
 * @brief Given a std::string, split by into a vector of std::string's based based on white space characters.
 *
 * @param s A std::string consisting of lower case english characters and single white splaces
 * @return std::vector<std::string> A vector of std::string's
 */
std::vector<std::string> splitWords(const std::string &s);

#endif