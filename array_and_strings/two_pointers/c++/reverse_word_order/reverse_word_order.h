// reverse_word_order.h
#ifndef REVERSE_WORD_ORDER_H
#define REVERSE_WORD_ORDER_H
#include <string>

/**
 * @brief Given a string s, reverse the order of the words.
 *
 * @param s String to reverse.
 * @param useBoostJoin If true, use boost::algorithm::join to join the words, otherwise use a loop.
 *
 * @return std::string Reversed string.
 * @note 1. Note that s may contain leading or trailing spaces or multiple spaces between two words.
 * @note 2. The returned string should only have a single space separating the words. Do not include any extra spaces.
 */
std::string reverseWordOrder(std::string &s, bool useBoostJoin = false);

#endif
