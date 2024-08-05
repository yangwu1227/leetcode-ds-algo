// rng_integer.cpp
#include "rng_integer.hpp"
#include <random>

int generateRandomInteger(int min, int max)
{
    // A uniformly-distributed integer random number generator
    std::random_device rnd_device;
    // Engine and distribution
    std::mt19937 mersenneEngine{rnd_device()};
    std::uniform_int_distribution<int> dist{min, max};

    return dist(mersenneEngine);
}
