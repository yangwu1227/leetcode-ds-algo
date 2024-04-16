// split_array.hpp
#ifndef SPLIT_ARRAY_HPP
#define SPLIT_ARRAY_HPP
#include <vector>

/**
 * @brief Given an integer array `nums`, find the number of ways to split the array into two parts so that the first section has a
 * sum greater than or equal to the sum of the second section. The second section should have at least one number.
 *
 * @param nums A vector of integers
 * @return int Number of ways to split the array into two parts while satisfying the criteria: `first_section_sum >= second_section_sum`
 */
int splitArray(const std::vector<int> &nums);

#endif
