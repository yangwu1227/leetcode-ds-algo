// custom_rng.cpp
#include <vector>
#include <random>
#include <algorithm>  // Include for std::sort
#include "custom_rng.hpp"

std::vector<int> generateRandomVector(size_t size, int min, int max)
{
    // A uniformly-distributed integer random number generator
    std::random_device rnd_device;
    // Engine and distribution
    std::mt19937 mersenneEngine{rnd_device()};
    std::uniform_int_distribution<int> dist{min, max};

    // Lambda function that takes a distribution and engine
    auto gen = [&dist, &mersenneEngine]()
    {
        return dist(mersenneEngine);
    };

    std::vector<int> vec(size);
    std::generate(begin(vec), end(vec), gen);
    std::sort(begin(vec), end(vec));
    return vec;
}
