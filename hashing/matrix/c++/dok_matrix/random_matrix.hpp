// random_matrix.hpp
#ifndef RANDOM_MATRIX_HPP
#define RANDOM_MATRIX_HPP
#include <vector>

/**
 * @brief Generates a random dense matrix.
 *
 * This function generates a dense matrix with the specified number of rows and columns.
 * Each element in the matrix is a random double value within the given range [min, max].
 *
 * @param rows The number of rows in the generated matrix.
 * @param cols The number of columns in the generated matrix.
 * @param min The minimum possible value for an element in the matrix.
 * @param max The maximum possible value for an element in the matrix.
 * @return A 2D vector representing the generated dense matrix with random values.
 */
std::vector<std::vector<double>> generateRandomMatrix(int rows, int cols, double min, double max);

#endif
