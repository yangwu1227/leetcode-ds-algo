// sort_string.hpp
#ifndef SORT_STRING_HPP
#define SORT_STRING_HPP
#include <string>

/**
 * @brief Given two strings `order` and `s`, all the characters of `order` are unique and are sorted in some custom order. Permute the characters
 * of `s` so that they match `order`. If a character `x` occurs before a character `y` in `order`, then `x` should occur before `y` in the permuted string.

 *
 * @param order A string consisting of lower case english letters
 * @param s A string consisting of lower case english letters
 * @return std::string Any permutation of `s` that is sorted based on `order`
 */
std::string sortString(const std::string &order, const std::string &s);

#endif