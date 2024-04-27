// destination_city.hpp
#ifndef DESTINATION_CITY_HPP
#define DESTINATION_CITY_HPP
#include <vector>
#include <string>

/**
 * @brief Given an array of paths, where `paths[i] = [cityA_i, cityB_i]` means there exists a direct path going from `cityA_i` to `cityB_i`. Return the destination city,
 * that is, the city without any path outgoing to another city.
 *
 * @param paths A vector of vectors of strings, each of which is a dep -> dest pair of cities
 * @return std::string Name of the destination city
 *
 * @note It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.
 */
std::string destCity(const std::vector<std::vector<std::string>> &paths);

#endif
