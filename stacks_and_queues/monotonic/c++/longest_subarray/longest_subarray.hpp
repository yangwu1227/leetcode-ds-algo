// longest_subarray.hpp
#ifndef LONGEST_SUBARRAY_HPP
#define LONGEST_SUBARRAY_HPP
#include <vector>

/**
 * @brief Given an array of integers `nums` and an integer `limit`, return the size of the longest non-empty subarray such that the absolute difference between
 * any two elements of this subarray is less than or equal to `limit`.
 *
 * @param nums An `std::vector` of integers
 * @param limit An integer limit
 * @return int The length of the longest continuous valid subarray
 */
int longestSubarray(const std::vector<int> &nums, int limit);

#endif
