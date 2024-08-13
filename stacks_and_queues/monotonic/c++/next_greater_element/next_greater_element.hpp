// next_greater_element.hpp
#ifndef NEXT_GREATER_ELEMENT_HPP
#define NEXT_GREATER_ELEMENT_HPP
#include <vector>

/**
 * @brief Given two distinct integer arrays `nums_1` and `nums_2` where `nums_1` is a subset of `nums_2`,
 * find the array `output` such that for each element `nums_1[i]`, `output[i]` contains the next greater element
 * of `nums_1[i]` in `nums_2`. If no such element exists, `output[i]` will be -1.
 *
 * @param nums_1 An `std::vector` of integers that is a subset of `nums_2`
 * @param nums_2 An `std::vector` integers where `nums_1` is a subset, used to determine the next greater element for each element in `nums_1`
 * @return std::vector<int> An `std::vector` where each element corresponds to the next greater element of the respective element in
 * `nums_1` found in `nums_2`; if there is no greater element, the corresponding value will be -1
 */
std::vector<int> nextGreaterElement(const std::vector<int> &nums_1, const std::vector<int> &nums_2);

#endif
