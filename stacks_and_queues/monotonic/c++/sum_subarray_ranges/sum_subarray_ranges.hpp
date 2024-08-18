// sum_subarray_ranges.hpp
#ifndef SUM_SUBARRAY_RANGES_HPP
#define SUM_SUBARRAY_RANGES_HPP
#include <vector>

/**
 * @brief Calculate the sum of all subarray ranges for the given array of integers.
 *
 * A subarray range is defined as the difference between the maximum and
 * minimum elements in that subarray. This function computes the sum of
 * all possible subarray ranges.
 *
 * @param nums An `std::vector` of integers for which the subarray ranges are to be calculated
 * @return long long The sum of all subarray ranges
 */
long long int sumSubarrayRanges(const std::vector<int> &nums);

#endif
