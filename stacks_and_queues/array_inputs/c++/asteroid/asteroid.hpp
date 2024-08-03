// asteroid.hpp
#ifndef ASTEROID_HPP
#define ASTEROID_HPP
#include <vector>

/**
 * @brief Simulates the collision of asteroids based on their size and direction. Each asteroid moves at the same speed. If
 * two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Asteroids moving in the
 * same direction will never meet.
 *
 * @param data A vector of integers representing asteroids in a row. The absolute value represents the size of the asteroid, and the sign
 *  represents its direction (positive for right, negative for left)

 * @return std::vector<int> The state of the asteroids after all collisions
 */
std::vector<int> asteroid(const std::vector<int> &data);

#endif
