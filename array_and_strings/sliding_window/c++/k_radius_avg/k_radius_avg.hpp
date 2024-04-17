// k_radius_avg.hpp
#ifndef K_RADIUS_AVG_HPP
#define K_RADIUS_AVG_HPP
#include <vector>

/**
 * @brief The k-radius average for a subarray of `nums` centered at index `i` with the radius `k` is the average of all elements in `nums` between the 
 * indices `i - k` and `i + k` (inclusive). If there are less than `k` elements before or after the index `i`, then the k-radius average is `-1`.
 * Build and return an array `avgs` of length `n` where `avgs[i]` is the k-radius average for the subarray centered at index `i`.
 * 
 * @param nums A vector of integers
 * @param k A non-negative integer
 * @return std::vector<int> The list of k-radius averages for the subarrays centered at each index of `nums`
 */
std::vector<int> findAverage(const std::vector<int> &nums, int k);

#endif
