// random_flip_matrix.hpp
#ifndef RANDOM_FLIP_MATRIX_HPP
#define RANDOM_FLIP_MATRIX_HPP
#include <unordered_map>
#include <vector>

/**
 * @class RandomFlip
 * @brief Given a `m x n` binary grid matrix with all the values set 0 initially. Design an algorithm to randomly pick an index `(i, j)` where
 * `matrix[i][j] == 0` and flips it to 1. All the indices `(i, j)` where `matrix[i][j] == 0` should be equally likely to be returned.
 */
class RandomFlip
{
public:
    /**
     * @brief Construct a new Random Flip object.
     *
     * @param m Number of rows in the matrix
     * @param n Number of columns in the matrix
     */
    RandomFlip(int m, int n);

    /**
     * @brief Randomly pick an index `(i, j)` where `matrix[i][j] == 0` and flips it to 1.
     *
     * @return std::vector<int> The index `(i, j)` that needs to be flipped to 1
     */
    std::vector<int> flip();

    /**
     * @brief Resets the matrix to its initial state, where all the values are set to 0.
     */
    void reset();

    /**
     * @brief Get the Available Indices member attribute.
     *
     * @return int
     */
    int getAvailableIndices() const;

private:
    int m;
    int n;
    int total;                                   // Total number of indices m x n
    int availableIndices;                        // Count of remaining available indices
    std::unordered_map<int, int> flippedIndices; // Used to keep track of flipped indices
};

#endif
