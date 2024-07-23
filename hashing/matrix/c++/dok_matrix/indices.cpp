// indices.cpp
#include "indices.hpp"
#include <boost/functional/hash.hpp>

// Constructor with initialization list
Indices::Indices(int row, int col) : i(row), j(col) {}

// This is needed in case of hash collisions so that the hash table can compare the actual objects
bool Indices::operator==(const Indices &other) const
{
    return i == other.i && j == other.j;
}

// Functor for hashing `Indices` objects
std::size_t Indices::Hash::operator()(const Indices &indices) const
{
    std::size_t seed = 0;
    boost::hash_combine(seed, indices.i);
    boost::hash_combine(seed, indices.j);
    return seed;
}
