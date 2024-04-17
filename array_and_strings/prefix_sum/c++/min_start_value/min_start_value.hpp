// min_start_value.hpp
#ifndef MIN_START_VALUE_HPP
#define MIN_START_VALUE_HPP
#include <vector>

/**
 * @brief Given an array of integers `nums`, start with an initial positive value `start_value`. In each iteration, 
 * calculate the step by step sum of `start_value + nums[i]` for `i, ..., n`, where `n` is the length of `nums`. 
 * Return the minimum positive `start_value` such that each of the `n` sums is never less than 1.
 * 
 * @param nums A vector of integers
 * @return int Minimum positive `start_value` that satisfies the criteria
 */
int minStartValue(const std::vector<int> &nums);

#endif
