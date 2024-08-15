// sorted_two_sum.hpp
#ifndef SORTED_TWO_SUM_HPP
#define SORTED_TWO_SUM_HPP

#include <vector>

/**
 * @brief Checks if there is a pair of numbers within the sorted (ascending) vector that sums up to the target value.
 * This function assumes the input vector is sorted in ascending order and iterates through the vector to find if
 * such a pair exists.
 *
 * @param nums Input vector of sorted (ascending) integers.
 * @param target Target integer.
 * @return true if there is a pair of numbers that sum to target, false if there is none.
 */
bool checkForTarget(std::vector<int> &nums, int target);

#endif
