// indices.hpp
#ifndef INDICES_HPP
#define INDICES_HPP
#include <cstddef>

/**
 * @class Indices
 *
 * @brief Represents a pair of hashable indices (row, column) for a sparse matrix.
 */
class Indices
{
public:
    /**
     * @brief Constructs an Indices object.
     *
     * @param row Row index
     * @param col Column index
     */
    Indices(int row, int col);

    /**
     * @brief Overload the equality operator to compare two Indices objects
     *
     * @param other The other Indices object to compare with
     * @return `true` if the indices are equal, false otherwise
     */
    bool operator==(const Indices &other) const;

    /**
     * @brief A custom hash function for `Indices` objects, utilizing `boost::hash_combine` to generate hash values.
     * This allows pairs of indices to be used as keys in standard hash table data structures like `std::unordered_map` and `std::unordered_set`.
     *
     * The `hash_combine` function provides a way to combine the hash values of individual elements of a pair, i.e., `i` and `j`, resulting in
     * a single hash value that considers both elements, minimizing collisions.
     */
    struct Hash
    {
        std::size_t operator()(const Indices &indices) const;
    };

private:
    int i;                     // Row index
    int j;                     // Column index
    friend class SparseMatrix; // Allow SparseMatrix to access private members of Indices
};

#endif
