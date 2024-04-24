// find_numbers.hpp
#ifndef FIND_NUMBERS_HPP
#define FIND_NUMBERS_HPP
#include <vector>

/**
 * @brief Given an integer array `nums`, find all the unique numbers `x` in nums that satisfy the following: `x + 1` is not in `nums`, and `x - 1 `is not in `nums`.
 * 
 * @param nums A vector of integers
 * @return std::vector<int> All values `x` in `nums` that satisfies the condition
 */
std::vector<int> findNumbers(const std::vector<int> &nums);

#endif
