// custom_bn_rng.h
#ifndef CUSTOM_BN_RNG_H
#define CUSTOM_BN_RNG_H
#include <vector>

/**
 * @brief Generate a random binary vector of integer with specified size.
 *
 * @param size Size of the vector.
 * @param p Probability of success of a single Bernoulli trial
 * @return std::vector<int> A vector of random binary integers
 */
std::vector<int> generateBinaryVector(size_t size, double p);

#endif
