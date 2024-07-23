// indices.cpp
#include "indices.hpp"
#include <boost/functional/hash.hpp>

Indices::Indices(int row, int col) : i(row), j(col) {}

bool Indices::operator==(const Indices &other) const
{
    return i == other.i && j == other.j;
}

std::size_t Indices::Hash::operator()(const Indices &indices) const
{
    std::size_t seed = 0;
    boost::hash_combine(seed, indices.i);
    boost::hash_combine(seed, indices.j);
    return seed;
}
