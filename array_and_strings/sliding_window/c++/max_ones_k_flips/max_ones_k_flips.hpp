// max_ones_k_flips.hpp
#ifndef MAX_ONES_K_FLIPS_HPP
#define MAX_ONES_K_FLIPS_HPP
#include <vector>

/**
 * @brief Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if we can flip at most k 0's.
 *
 * @param nums A binary vector of 1's and 0's
 * @param k An integer of length
 * @return int Maximum number of consecutive 1's
 */
int longestOnes(const std::vector<int> &nums, const int &k);

#endif
