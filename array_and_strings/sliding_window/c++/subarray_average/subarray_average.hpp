// subarray_average.h
#ifndef SUBARRAY_AVERAGE_H
#define SUBARRAY_AVERAGE_H
#include <vector>

/**
 * @brief Given an integer array nums consisting of n elements, and an integer k. Find a contiguous subarray whose length is equal to k that has the
 * maximum average value and return this value.
 *
 * @param nums A vector of integers
 * @param k An integer representing the length of the subarray
 * @return double The maximum average value of the subarray
 */
double findMaxAverage(const std::vector<int> &nums, const int &k);

#endif
