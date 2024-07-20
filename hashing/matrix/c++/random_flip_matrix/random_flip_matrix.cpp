// random_flip_matrix,.cpp
#include "random_flip_matrix.hpp"
#include "rng_integer.hpp"
#include <unordered_map>
#include <vector>

RandomFlip::RandomFlip(int m, int n) : m(m), n(n), total(m * n), availableIndices(total) {}

int RandomFlip::getAvailableIndices() const
{
    return this->availableIndices;
}

std::vector<int> RandomFlip::flip()
{
    if (this->availableIndices == 0)
    {
        return std::vector<int>();
    }

    // Random index in the range 0, ..., m * n
    int randomIndex = generateRandomInteger(0, this->availableIndices - 1);
    --this->availableIndices;

    // If randomIndex is already flipped, set it to a previous count of available index, if it hasn't been flipped yet, use it directly
    auto findRandomIndex = this->flippedIndices.find(randomIndex);
    int indexToFlip = (findRandomIndex != this->flippedIndices.end()) ? findRandomIndex->second : randomIndex;

    // Map the current random index to the current count of available index or, if the current count of available index already exist as a key, to a previous count of available index
    this->flippedIndices[randomIndex] = (this->flippedIndices.count(this->availableIndices) > 0) ? this->flippedIndices[this->availableIndices] : this->availableIndices;

    return {indexToFlip / this->n, indexToFlip % this->n};
}

void RandomFlip::reset()
{
    this->availableIndices = this->total;
    this->flippedIndices.clear();
}
