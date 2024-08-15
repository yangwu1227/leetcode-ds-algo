// product_less_than_k.hpp
#ifndef PRODUCT_LESS_THAN_K_HPP
#define PRODUCT_LESS_THAN_K_HPP
#include <vector>

/**
 * @brief Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.
 *
 * @param nums A vector of positive integers
 * @param k An integer
 * @return int The number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k
 */
int numSubarraysProductLessThanK(const std::vector<int> &nums, const int &k);

#endif
