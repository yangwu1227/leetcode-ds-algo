// subarray_sum.hpp
#ifndef SUBARRAY_SUM_HPP
#define SUBARRAY_SUM_HPP
#include <vector>

/**
 * @brief Given an integer array nums and an integer k, find the sum of the subarray with the largest sum whose length is k.
 * 
 * @param nums A vector of integers
 * @param k An integer
 * @return int The sum of the subarray with the largest sum with length k
 */
int findBestSubarray(const std::vector<int> &nums, const int &k);

#endif
