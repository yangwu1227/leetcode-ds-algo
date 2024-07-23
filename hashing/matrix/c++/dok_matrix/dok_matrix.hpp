// dok_matrix.hpp
#ifndef DOK_MATRIX_HPP
#define DOK_MATRIX_HPP
#include "indices.hpp"
#include <vector>
#include <unordered_map>
#include <variant>

/**
 * @brief A sparse matrix class using a dictionary of keys (DOK) representation.
 */
class SparseMatrix
{
public:
    int nrows;
    int ncols;
    std::unordered_map<Indices, double, Indices::Hash> sparseMatrix;

    /**
     * @brief Constructs a SparseMatrix object.
     *
     * @param nrows Number of rows in the matrix.
     * @param ncols Number of columns in the matrix.
     * @param sparseMatrix Dictionary of keys representation of the sparse matrix.
     */
    SparseMatrix(int nrows, int ncols, const std::unordered_map<Indices, double, Indices::Hash> &sparseMatrix);

    /**
     * @brief Converts the sparse matrix to a dense matrix representation.
     *
     * @return A dense matrix representation of the sparse matrix.
     */
    std::vector<std::vector<double>> toDense() const;

    /**
     * @brief Converts a dense matrix to a sparse matrix representation.
     *
     * @param denseMatrix The dense matrix to convert.
     * @return A dictionary of keys sparse matrix representation.
     */
    static std::unordered_map<Indices, double, Indices::Hash> toSparse(const std::vector<std::vector<double>> &denseMatrix);

    /**
     * @brief Performs matrix multiplication between two sparse matrices.
     *
     * @param other The other sparse matrix to multiply with.
     * @return The result of the matrix multiplication.
     */
    SparseMatrix operator*(const SparseMatrix &other) const;

    /**
     * @brief Creates a sparse matrix instance from a dense matrix.
     *
     * @param denseMatrix The dense matrix to create the sparse matrix from.
     * @return A SparseMatrix instance.
     */
    static SparseMatrix fromDense(const std::vector<std::vector<double>> &denseMatrix);
};

#endif
