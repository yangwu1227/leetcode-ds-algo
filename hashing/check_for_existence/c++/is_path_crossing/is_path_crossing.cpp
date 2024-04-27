// is_path_crossing.hpp
#include "is_path_crossing.hpp"
#include <string>
#include <unordered_set>
#include <boost/functional/hash.hpp>

template <class T1, class T2>
std::size_t pairHash::operator()(const std::pair<T1, T2> &pair) const
{
    std::size_t seed = 0;
    boost::hash_combine(seed, pair.first);
    boost::hash_combine(seed, pair.second);
    return seed;
}

bool isPathCrossing(const std::string &path)
{
    std::unordered_set<std::pair<int, int>, pairHash> coordinates;
    auto [x, y] = std::make_pair(0, 0);
    coordinates.emplace(x, y);

    // O(n)
    for (const auto &direction : path)
    {
        switch (direction)
        {
        case 'N':
            y++;
            break;
        case 'S':
            y--;
            break;
        case 'E':
            x++;
            break;
        case 'W':
            x--;
            break;
        }
        // Check if this point has been visited O(1)
        if (coordinates.emplace(x, y).second)
        {
            // If emplace failed, coordinate was already in existent
            return true;
        }
    }

    return false;
}
