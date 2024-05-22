// max_subarray.hpp
#ifndef MAX_SUBARRAY_HPP
#define MAX_SUBARRAY_HPP
#include <vector>

/**
 * @brief Given an integer array `nums` and an integer `k`, return the length of the longest valid array.
 *
 * @param nums A sequence of positive integers
 * @param k A positive constraint
 * @return int The longest subarray whose elements have counts less than or equal to `k`
 */
int maxSubarrayLength(const std::vector<int> &nums, int k);

#endif
