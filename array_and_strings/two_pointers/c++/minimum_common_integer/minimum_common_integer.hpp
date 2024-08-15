// minimum_common_integer.hpp
#ifndef MINIMUM_COMMON_INTEGER_HPP
#define MINIMUM_COMMON_INTEGER_HPP
#include <vector>

/**
 * @brief Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays.
 * If there is no common integer amongst nums1 and nums2, return -1.
 *
 * @param nums1 The first integer array sorted in non-decreasing order
 * @param nums2 The second integer array sorted in non-decreasing order
 *
 * @note An integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.
 */
int getCommon(const std::vector<int> &nums1, const std::vector<int> &nums2);

#endif
