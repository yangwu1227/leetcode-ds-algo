// daily_temperatures.hpp
#ifndef DAILY_TEMPERATURES_HPP
#define DAILY_TEMPERATURES_HPP
#include <vector>

/**
 * @brief Given an array of integers `temperatures` representing daily temperatures, return an array `output` where `output[i]`
 * indicates the number of days after the `i`-th day that a warmer temperature occurs. If no such day exists, set `out[i]` to 0.
 *
 * @param temperatures An `std::vector` of integers representing temperatures on each day
 * @return std::vector<int> An `std::vector` of integers representing the numbers of elapsed days
 */
std::vector<int> dailyTemperatures(const std::vector<int> &temperatures);

#endif
