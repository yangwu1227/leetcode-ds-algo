// indices.hpp
#ifndef INDICES_HPP
#define INDICES_HPP
#include <utility>

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
class Indices
{
public:
    /**
     * @brief Constructs an Indices object.
     *
     * @param row Row index.
     * @param col Column index.
     */
    Indices(int row, int col);

    /**
     * @brief Equality operator to compare two Indices objects.
     *
     * @param other The other Indices object to compare with.
     * @return true if the indices are equal, false otherwise.
     */
    bool operator==(const Indices &other) const;

    /**
     * @brief Custom hash function for Indices.
     */
    struct Hash
    {
        std::size_t operator()(const Indices &indices) const;
    };

private:
    int i; ///< Row index
    int j; ///< Column index
    friend class SparseMatrix;
};

#endif
