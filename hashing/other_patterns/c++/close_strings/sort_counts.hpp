// sort_counts.hpp
#ifndef SORT_COUNTS_HPP
#define SORT_COUNTS_HPP
#include <vector>
#include <unordered_map>

/**
 * @brief Given an `std::unordered_map<char, int>`, load the values into a vector and sort the vector.
 * 
 * @param countsMap A hash map with character literals as keys and integers as values
 * @return std::vector<int> A sorted vector containing the hash map values
 */
std::vector<int> sortCounts(const std::unordered_map<char, int> &countsMap);

#endif