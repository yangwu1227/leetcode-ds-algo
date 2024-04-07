// custom_bn_rng.cpp
#include "custom_bn_rng.h"
#include <vector>
#include <random>

std::vector<int> generateBinaryVector(size_t size, double p)
{
    // Ensure that p is within 0 and 1 or else raise exception
    if (p < 0.0 || p > 1.0) {
        throw std::invalid_argument("Probability p must be between 0 and 1.");
    }

    // A Bernoulli-distributed integer random number generator
    std::random_device rnd_device;
    // Engine and distribution
    std::mt19937 mersenneEngine{rnd_device()};
    std::bernoulli_distribution dist(p);

    // Lambda function that takes a distribution and engine
    auto gen = [&dist, &mersenneEngine]()
    {
        return dist(mersenneEngine);
    };

    // Reserve capacity to avoid reallocations
    std::vector<int> vec;
    vec.reserve(size);

    for (size_t i = 0; i < size; ++i)
    {
        // Fill vector with 0 or 1 with probability of success, p
        vec.push_back(static_cast<int>(gen()));
    }

    return vec;
}
