// count_elements.hpp
#ifndef COUNT_ELEMENTS_HPP
#define COUNT_ELEMENTS_HPP
#include <vector>

/**
 * @brief Given an integer `array`, count how many elements `x` there are, such that `x + 1` is also in `array`.
 * If there are duplicates in `array`, count them separately.
 *
 * @param array A vector of positive integers
 * @return int Number of elements `x` such that `x + 1` is also in the array
 */
int countElements(const std::vector<int> &array);

#endif
