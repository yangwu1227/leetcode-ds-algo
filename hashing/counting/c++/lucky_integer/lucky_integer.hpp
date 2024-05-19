// lucky_integer.hpp
#ifndef LUCKY_INTEGER_HPP
#define LUCKY_INTEGER_HPP
#include <vector>

/**
 * @brief A lucky integer is defined as an integer that has a count equaling its value. Given an array of integers, return the largest lucky integer in the array.
 *
 * @param nums A vector of positive integers
 * @return int Largest lucky integer or -1 if no such integer exists
 */
int findLuckyInteger(const std::vector<int> &nums);

#endif
