// is_path_crossing.hpp
#ifndef IS_PATH_CROSSING_HPP
#define IS_PATH_CROSSING_HPP
#include <string>

/**
 * @brief A custom hash function for `std::pair` instances, utilizing Boost's `hash_combine` to generate hash values.
 * This allows pairs to be used as keys in standard containers like `std::unordered_map` and `std::unordered_set`.
 *
 * The `hash_combine` function provides a way to combine the hash values of individual elements of a pair,
 * resulting in a single hash value that considers both elements, minimizing collisions.
 *
 * @param T1 Type of the first element in the pair.
 * @param T2 Type of the second element in the pair.
 */
class PairHash
{
public:
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &pair) const;
};

/**
 * @brief Given a string path, where `path[i] = 'N', 'S', 'E' or 'W'`, each representing moving one unit north, south, east, or west, respectively.
 * Start at the origin `(0, 0)` on a 2D plane and walk on the path specified by `path`.
 *
 * @param path A string containing characters of either 'N', 'S', 'E' or 'W'
 * @return bool `true` if the path crosses itself at any point, i.e. returning to a point previously visited, `false` otherwise
 */
bool isPathCrossing(const std::string &path);

#endif
