// sum_subarray_mins.hpp
#ifndef SUM_SUBARRAY_MINS_HPP
#define SUM_SUBARRAY_MINS_HPP
#include <vector>

/**
 * @brief Calculate the sum of the minimum values of all subarrays in the given sequence.
 *
 * @param x An `std::vector` of integers for which the sum of minimums of all subarrays is to be calculated
 * @return int The sum of the minimum values of all subarrays in the sequence, modulo 10**9 + 7
 */
int sumSubarrayMins(const std::vector<int> &x);

#endif
