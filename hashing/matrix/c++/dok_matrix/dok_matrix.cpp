// dok_matrix.cpp
#include "dok_matrix.hpp"
#include "indices.hpp"
#include <vector>
#include <variant>
#include <stdexcept>

// Constructor
SparseMatrix::SparseMatrix(int nrows, int ncols, const std::unordered_map<Indices, double, Indices::Hash> &sparseMatrix)
    : nrows(nrows), ncols(ncols), sparseMatrix(sparseMatrix) {}

// Sparse to dense
std::vector<std::vector<double>> SparseMatrix::toDense() const
{
    std::vector<std::vector<double>> denseMatrix(nrows, std::vector<double>(ncols, 0));
    for (const auto &element : sparseMatrix)
    {
        denseMatrix[element.first.i][element.first.j] = element.second;
    }
    return denseMatrix;
}

// Dense to sparse
std::unordered_map<Indices, double, Indices::Hash> SparseMatrix::toSparse(const std::vector<std::vector<double>> &denseMatrix)
{
    std::unordered_map<Indices, double, Indices::Hash> sparseMatrix;
    for (int i = 0; i < denseMatrix.size(); ++i)
    {
        for (int j = 0; j < denseMatrix[i].size(); ++j)
        {
            if (denseMatrix[i][j] != 0)
            {
                sparseMatrix[Indices(i, j)] = denseMatrix[i][j];
            }
        }
    }
    return sparseMatrix;
}

// Overload matrix multiplication operator
SparseMatrix SparseMatrix::operator*(const SparseMatrix &other) const
{
    if (ncols != other.nrows)
    {
        throw std::invalid_argument("Matrix dimensions do not match for multiplication");
    }

    std::unordered_map<Indices, double, Indices::Hash> resultSparseMatrix;
    for (const auto &element : sparseMatrix)
    {

        // A[this_row_idx, common_idx]
        int this_row_idx = element.first.i;
        int common_idx = element.first.j;
        // Each 'element' is a mapping of Indices -> double, which is a non-zero cell value at idx (i, j)
        // Therefore, element.first is a Indices object and element.second is the cell value
        double self_value = element.second;

        for (int other_col = 0; other_col < other.ncols; ++other_col)
        {
            Indices other_key(common_idx, other_col);
            //  If `B[common_idx, other_col_idx]` is also non-zero, then `A[this_row_idx, common_idx]` x `B[common_idx, other_col_idx]`
            if (other.sparseMatrix.find(other_key) != other.sparseMatrix.end())
            {
                double other_value = other.sparseMatrix.at(other_key);
                Indices result_key(this_row_idx, other_col);
                // The first call to operator[] initializes the C[this_row_idx, other_col_idx] to zero
                resultSparseMatrix[result_key] += self_value * other_value;
            }
        }
    }
    return SparseMatrix(nrows, other.ncols, resultSparseMatrix);
}

// Class method to construct a SparseMatrix from a vector of vectors
SparseMatrix SparseMatrix::fromDense(const std::vector<std::vector<double>> &denseMatrix)
{
    int rows = denseMatrix.size();
    int cols = denseMatrix[0].size();
    auto sparseMatrix = toSparse(denseMatrix);
    return SparseMatrix(rows, cols, sparseMatrix);
}
