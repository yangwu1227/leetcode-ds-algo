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

// Dense to sparse, which will be called internally by the fromDense method
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

// Class method to construct a SparseMatrix from a vector of vectors
SparseMatrix SparseMatrix::fromDense(const std::vector<std::vector<double>> &denseMatrix)
{
    int rows = denseMatrix.size();
    int cols = denseMatrix[0].size();
    auto sparseMatrix = toSparse(denseMatrix);
    return SparseMatrix(rows, cols, sparseMatrix);
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
        int rowIdxFromA = element.first.i;
        int commonIdx = element.first.j;
        // Each 'element' is a mapping of Indices -> double, which is a non-zero cell value at A[rowIdxFromA, commonIdx]
        // Therefore, element.first is an Indices object and element.second is the cell value
        double cellValueA = element.second;

        // Iterate over the columns of the right-hand matrix
        for (int columnIdxFromB = 0; columnIdxFromB < other.ncols; ++columnIdxFromB)
        {
            Indices nonZeroIndicesB(commonIdx, columnIdxFromB);
            //  If `B[commonIdx, columnIdxFromB]` is also non-zero, then carry out the multiplication `A[rowIdxFromA, commonIdx]` x `B[commonIdx, columnIdxFromB]`
            if (other.sparseMatrix.find(nonZeroIndicesB) != other.sparseMatrix.end())
            {
                double cellValueB = other.sparseMatrix.at(nonZeroIndicesB);
                Indices outputIndicesC(rowIdxFromA, columnIdxFromB);
                // The first call to operator[] initializes the element C[rowIdxFromA, columnIdxFromB] to zero
                // If there are additional non-zero elements other columns of B, they will be added to this value in the next iterations
                resultSparseMatrix[outputIndicesC] += cellValueA * cellValueB;
            }
        }
    }
    return SparseMatrix(nrows, other.ncols, resultSparseMatrix);
}
