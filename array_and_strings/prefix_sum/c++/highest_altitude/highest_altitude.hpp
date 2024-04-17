// highest_altitude.hpp
#ifndef HIGHEST_ALTITUDE_HPP
#define HIGHEST_ALTITUDE_HPP
#include <vector>

/**
 * @brief A road trip consists of `n + 1` points at different altitudes. The start point is `altitude = 0`. Given an integer array `gain` of
 * length `n` where `gain[i]` is the net gain in altitude between points `i` and `i + 1` for all (`0 <= i < n`), return the highest altitude of a point.
 *
 * @param gain An integer array `gain` of length `n` where `gain[i]` is the net gain in altitude between points `i` and `i + 1` for all (`0 <= i < n`)
 * @return int The highest altitude of a point
 */
int highestAltitude(const std::vector<int> &gain);

#endif
