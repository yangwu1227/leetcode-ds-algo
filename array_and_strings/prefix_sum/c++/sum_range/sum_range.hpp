// sum_range.hpp
#ifndef SUM_RANGE_HPP
#define SUM_RANGE_HPP
#include <vector>

class NumArray
{
public:
    std::vector<int> nums;
    std::vector<int> prefix;
    /**
     * @brief Construct a new Num Array object.
     *
     * @param inputs A vector of integers
     */
    NumArray(const std::vector<int> &inputs);

    /**
     * @brief Given an integer array `nums`, a `left` and `right` index, find the
     * sum of all elements between `left` and `right` inclusive.
     *
     * @throw std::out_of_range if indices are out of bounds or `left` > `right`.
     *
     * @param left An integer representing the start of the subarray
     * @param right An integer representing the end of the subarray
     *
     * @return int The sum of all elements in the subarray
     */
    int sumRange(int left, int right) const;
};

#endif
