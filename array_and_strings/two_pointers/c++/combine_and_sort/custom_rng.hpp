// custom_rng.hpp
#ifndef CUSTOM_RNG_HPP
#define CUSTOM_RNG_HPP

#include <vector>

/**
 * @brief Generate a random vector of integer with specified size and range.
 *
* @param size Size of the vector.
* @param min Minimum value of the integers.
* @param max Maximum value of the integers.
* @return std::vector<int> A vector of random integers, sorted in ascending order.
*/
std::vector<int> generateRandomVector(size_t size, int min, int max);

#endif
