// main.cpp
#include "dok_matrix.hpp"
#include "random_matrix.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <Eigen/Sparse>
#include <Eigen/Dense>

/* --------------------------- Print dense matrix --------------------------- */

void printDenseMatrix(const std::vector<std::vector<double>> &matrix)
{
    int rows = matrix.size();
    int cols = rows > 0 ? matrix[0].size() : 0;

    // Print column headers
    std::cout << "     "; // Initial padding for row headers
    for (int j = 0; j < cols; ++j)
    {
        std::cout << std::setw(8) << j << " ";
    }
    std::cout << '\n';

    // Print separator
    std::cout << "    ";
    for (int j = 0; j < cols; ++j)
    {
        std::cout << "---------";
    }
    std::cout << '\n';

    // Print matrix with row indices
    for (int i = 0; i < rows; ++i)
    {
        std::cout << std::setw(3) << i << " |";
        for (int j = 0; j < cols; ++j)
        {
            std::cout << std::setw(8) << std::setprecision(3) << matrix[i][j] << " ";
        }
        std::cout << '\n';
    }
    std::cout << std::endl;
}

/* ------------------------- A single test case run ------------------------- */

void testMatrixMultiplication(int rows1, int cols1, int rows2, int cols2)
{
    // Generate random dense matrices
    auto dense_matrix_1 = generateRandomMatrix(rows1, cols1, -10.0, 10.0);
    auto dense_matrix_2 = generateRandomMatrix(rows2, cols2, -10.0, 10.0);

    std::cout << "Matrix 1 (dense):" << std::endl;
    printDenseMatrix(dense_matrix_1);
    std::cout << "Matrix 2 (dense):" << std::endl;
    printDenseMatrix(dense_matrix_2);

    /* ------------------- Custom SparseMatrix multiplication ------------------- */

    // Create instances of SparseMatrix
    SparseMatrix sparseMatrix1 = SparseMatrix::fromDense(dense_matrix_1);
    SparseMatrix sparseMatrix2 = SparseMatrix::fromDense(dense_matrix_2);
    SparseMatrix outputCustomSparse = sparseMatrix1 * sparseMatrix2;
    // Convert output matrix back to dense representation
    std::vector<std::vector<double>> outoutCustomDense = outputCustomSparse.toDense();

    /* --------------------------- Check against Eigen -------------------------- */

    // Declare a column-major sparse matrix type of double
    typedef Eigen::SparseMatrix<double> EigenSparseMatrix;
    typedef Eigen::Triplet<double> T;
    // Build triplets
    std::vector<T> tripletList1;
    std::vector<T> tripletList2;
    for (int i = 0; i < rows1; ++i)
    {
        for (int j = 0; j < cols1; ++j)
        {
            if (dense_matrix_1[i][j] != 0)
            {
                tripletList1.push_back(T(i, j, dense_matrix_1[i][j]));
            }
        }
    }
    for (int i = 0; i < rows2; ++i)
    {
        for (int j = 0; j < cols2; ++j)
        {
            if (dense_matrix_2[i][j] != 0)
            {
                tripletList2.push_back(T(i, j, dense_matrix_2[i][j]));
            }
        }
    }
    EigenSparseMatrix eigenSparseMatrix1(rows1, cols1);
    EigenSparseMatrix eigenSparseMatrix2(rows2, cols2);
    eigenSparseMatrix1.setFromTriplets(tripletList1.begin(), tripletList1.end());
    eigenSparseMatrix2.setFromTriplets(tripletList2.begin(), tripletList2.end());
    // Matrix multiplication
    EigenSparseMatrix outputEigenSparse = eigenSparseMatrix1 * eigenSparseMatrix2;

    /* ----------------------------- Compare results ---------------------------- */

    // Convert custom sparse matrix result to Eigen dense matrix
    Eigen::MatrixXd outputCustomDenseEigen(rows1, cols2);
    for (int i = 0; i < rows1; ++i)
    {
        for (int j = 0; j < cols2; ++j)
        {
            outputCustomDenseEigen(i, j) = outoutCustomDense[i][j];
        }
    }
    // Convert Eigen sparse matrix result to dense matrix
    Eigen::MatrixXd outputEigenDense = Eigen::MatrixXd(outputEigenSparse);

    // Check if the results are approximately equal
    if (outputCustomDenseEigen.isApprox(outputEigenDense))
    {
        std::cout << "The results are approximately equal" << '\n';
    }
    else
    {
        std::cout << "The results are not approximately equal" << '\n';
    }
}

int main()
{

    std::srand(std::time(0));
    // Test 5 random cases
    for (int i = 0; i < 5; ++i)
    {
        int rows1 = std::rand() % 5 + 1;
        int cols1 = std::rand() % 5 + 1;
        int rows2 = cols1;
        int cols2 = std::rand() % 5 + 1;

        std::cout << "Test case " << i + 1 << ": " << '\n';
        std::cout << "Matrix 1: " << rows1 << "x" << cols1 << '\n';
        std::cout << "Matrix 2: " << rows2 << "x" << cols2 << '\n';

        testMatrixMultiplication(rows1, cols1, rows2, cols2);
        std::cout << '\n';
    }
    std::cout << std::endl;

    return 0;
}
