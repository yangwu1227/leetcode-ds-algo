// binary_subarray_sum.hpp
#ifndef BINARY_SUBARRAY_SUM_HPP
#define BINARY_SUBARRAY_SUM_HPP
#include <vector>

/**
 * @brief Given a binary array `nums` and an integer `k`, return the number of non-empty subarrays with a sum `k`.
 *
 * @param nums A vector of 1's or 0's
 * @param k A positive sum constraint
 * @return int Number of valid subarrays
 */
int binarySubarraySum(const std::vector<int> &nums, int k);

#endif
