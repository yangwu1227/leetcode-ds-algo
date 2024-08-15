// combine_and_sort.hpp
#ifndef COMBINE_AND_SORT_HPP
#define COMBINE_AND_SORT_HPP

#include <vector>

/**
 * @brief Given two 'sorted' integer arrays arr1 and arr2, return a new array that combines both of them and is also sorted.
 *
 * @param arr1 Input vector 1 of sorted (ascending) integers.
 * @param arr2 Input vector 2 of sorted (ascending) integers.
 * @return std::vector<int> A new vector that combines both input vectors and is also sorted.
 */
std::vector<int> combine(const std::vector<int> &arr1, const std::vector<int> &arr2);

#endif
