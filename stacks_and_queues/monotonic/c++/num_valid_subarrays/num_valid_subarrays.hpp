// num_valid_subarrays.hpp
#ifndef NUM_VALID_SUBARRAYS_HPP
#define NUM_VALID_SUBARRAYS_HPP
#include <vector>

/**
 * @brief Returns the number of non-empty subarrays where the leftmost element is not larger than any other elements in the subarray.
 *
 * @param nums An `std::vector` of integers representing the input array
 * @return int The total number of valid subarrays
 */
int numValidSubarrays(const std::vector<int> &nums);

#endif
