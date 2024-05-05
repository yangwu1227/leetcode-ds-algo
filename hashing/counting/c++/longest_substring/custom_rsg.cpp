// custom_rsg.cpp
#include "custom_rsg.hpp"
#include <string>
#include <random>

std::string generateRandomString(std::size_t length)
{
    // Lower case english letters
    const std::string characters = "abcdefghijklmnopqrstuvwxyz";

    std::random_device rnd_device;
    std::mt19937 mersenneEngine{rnd_device()};
    std::uniform_int_distribution<int> dist(0, characters.size() - 1);

    std::string randomString;
    randomString.reserve(length);

    // [&] is the capture clause with capture default &, which captures all variables in the enclosing environment by reference
    // () is the parameter list, which is empty, and we could have not included it
    // {return ...} is the lambda body
    // Then, generate_n takes three arguments: first (the beginning of the range of elements to generate), count (number of elements to generate), g (generator function object)
    std::generate_n(std::back_inserter(randomString), length, [&](){ return characters[dist(mersenneEngine)]; });

    return randomString;
}
