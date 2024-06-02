// max_sum_pairs.hpp
#ifndef MAX_SUM_PAIRS_HPP
#define MAX_SUM_PAIRS_HPP
#include <vector>

/**
 * @brief Given an array of integers `nums`, find the maximum value of `nums[i] + nums[j]`, where `nums[i]` and `nums[j]`
 * have the same digit sum (the sum of their individual digits).
 *
 * @param nums A vector of positive integers
 * @return int The maximum value of `nums[i] + nums[j]`, where `nums[i]` and `nums[j]` have the same digit sum, or -1 if no such pair exists
 */
int maxSum(const std::vector<int> &nums);

#endif