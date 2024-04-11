// equal_substring.h
#ifndef EQUAL_SUBSTRING_H
#define EQUAL_SUBSTRING_H
#include <string>

/**
 * @brief Given two strings `s` and `t` of the same length and an integer `max_cost`, change `s` to `t`, change `s` to `t`.
 * Changing the ith character of `s` to ith character of `t` costs `|s[i] - t[i]|` (i.e., the absolute difference between
 * the ASCII values of the characters). Return the maximum length of a substring of `s` that can be changed to be the
 * same as the corresponding substring of `t` with a cost less than or equal to `max_cost`. If there is no substring from `s`
 * that can be changed to its corresponding substring from `t`, return 0.
 *
 * @param s A string consisting of lowercase english letters
 * @param t A string consisting of lowercase english letters
 * @param maxCost n integer representing the maximum cost allowed to change `s` to `t`
 * @return int The maximum length of a substring of `s` that can be changed to be the same as the corresponding substring of `t` with a cost less than or equal to `max_cost`
 */
int equalSubstring(const std::string &s, const std::string &t, const int maxCost);

#endif
