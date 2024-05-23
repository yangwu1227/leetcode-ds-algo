// num_identical_pairs.hpp
#ifndef NUM_IDENTICAL_PAIRS_HPP
#define NUM_IDENTICAL_PAIRS_HPP
#include <vector>

/**
 * @brief Given an array of integers `nums`, return the number of valid pairs. A pair of elements `(i, j)` is valid if `nums[i] == nums[j]` and `i < j`.
 *
 * @param nums A vector of positive integers
 * @return int Number of valid pairs
 */
int numIdenticalPairs(const std::vector<int> &nums);

#endif
