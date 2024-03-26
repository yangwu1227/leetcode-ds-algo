// palindrome.h
#ifndef PALINDROME_H
#define PALINDROME_H

#include <string>

/**
 * @brief Checks if the provided string is a palindrome. A palindrome is a string that reads the same 
 * backward as forward. This function iterates over the string from both ends towards the center, comparing 
 * characters for equality.
 * 
 * @param s The string to check, passed by constant reference to avoid copying.
 * @return true if `s` is a palindrome, false if not.
 */
bool checkIfPalindrome(const std::string& s);

#endif
