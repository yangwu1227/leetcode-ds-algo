// pivot_index.hpp
#ifndef PIVOT_INDEX_HPP
#define PIVOT_INDEX_HPP
#include <vector>

/**
 * @brief Given an array of integers `nums`, calculate the pivot index of this array. The pivot index is the index where the sum of all the numbers strictly
 * to the left of the index is equal to the sum of all the numbers strictly to the index's right.
 *
 * If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the
 * right edge of the array.
 *
 * @param nums A vector of integers
 * @return int The leftmost pivot index, or, if such index exists, -1
 */
int pivotIndex(const std::vector<int> &nums);

#endif
