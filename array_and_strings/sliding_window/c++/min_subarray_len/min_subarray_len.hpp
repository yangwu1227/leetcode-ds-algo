// min_subarray_len.hpp
#ifndef MIN_SUBARRAY_LEN_HPP
#define MIN_SUBARRAY_LEN_HPP
#include <vector>

/**
 * @brief Given an array of positive integers `nums` and a positive integer `target`, return the minimal length of a subarray whose sum
 * is greater than or equal to target. If there is no such subarray, return 0 instead.
 *
 * @param nums A vector of positive integers
 * @param target A positive integer
 * @return int Minimal length of a subarray whose sum is greater than or equal to target
 */
int minSubarrayLen(const std::vector<int> &nums, int target);

#endif
