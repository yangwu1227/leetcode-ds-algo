// remove_k_digits.hpp
#ifndef REMOVE_K_DIGITS_HPP
#define REMOVE_K_DIGITS_HPP
#include <string>

/**
 * @brief Remove k digits from the given number to produce the smallest possible number. Note that the input `std::string` is modified in place.
 *
 * @param num The original number given as a string of digits
 * @param k The number of digits to remove from the original number
 *
 * @return std::string The smallest possible number as a string after removing k digits; if the resulting number is empty or only contains zeros, '0' is returned
 */
std::string removeKDigits(std::string &num, int k);

#endif
