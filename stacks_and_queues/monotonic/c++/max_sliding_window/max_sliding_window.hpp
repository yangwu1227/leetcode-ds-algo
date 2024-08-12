// max_sliding_window.hpp
#ifndef MAX_SLIDING_WINDOW_HPP
#define MAX_SLIDING_WINDOW_HPP
#include <vector>

/**
 * @brief Given an array of integers `nums` and a sliding window of size `k`, this function processes the array by sliding the window
 * from the left to the right. At each position, the window contains `k` consecutive elements from `nums`.
 *
 * @param nums An `std::vector` of integers
 * @param k The size of the sliding window
 * @return std::vector<int> An `std::vector` of integers where each element is the maximum value of the corresponding sliding window of size `k`
 */
std::vector<int> maxSlidingWindow(const std::vector<int> &nums, int k);

#endif
