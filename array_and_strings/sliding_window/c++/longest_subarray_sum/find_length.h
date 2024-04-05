// find_length.h
#ifndef FIND_LENGTH_H
#define FIND_LENGTH_H
#include <vector>

/**
 * @brief Given an array of positive integers nums and an integer k, find the length of the longest subarray whose sum is less than or equal to k.
 *
 * @param nums array of positive integers
 * @param k integer
 *
 * @return length of the longest subarray whose sum is less than or equal to k
 */
int findLength(const std::vector<int> &nums, const int &k);

#endif
