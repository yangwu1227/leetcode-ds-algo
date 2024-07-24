// valid_parentheses.hpp
#ifndef VALID_PARENTHESES_HPP
#define VALID_PARENTHESES_HPP
#include <string>

/**
 * @brief Given a string `s` containing characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid. An input string is valid if the conditions in the
 * notes are satisfied.
 *
 * @param s A string containig different types of parentheses
 * @return bool `true` if the string is valid, otherwise `false`
 *
 * @note Open brackets must be closed by the same type of brackets
 * @note Open brackets must be closed in the correct order
 * @note Every close bracket has a corresponding open bracket of the same type
 */
bool validParentheses(const std::string &s);

#endif
