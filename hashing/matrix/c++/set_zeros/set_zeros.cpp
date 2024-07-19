// set_zeros.cpp
#include "set_zeros.hpp"
#include <vector>
#include <unordered_set>
#include <Eigen/Dense>

void SetZeros::hashApproach(std::vector<std::vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    std::unordered_set<int> rowsToZero;
    std::unordered_set<int> colsToZero;

    // First pass to identify rows and cols to zero
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (matrix[row][col] == 0)
            {
                rowsToZero.insert(row);
                colsToZero.insert(col);
            }
        }
    }

    // Second pass to set elements to zeros
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (rowsToZero.find(row) != rowsToZero.end() || colsToZero.find(col) != colsToZero.end())
            {
                matrix[row][col] = 0;
            }
        }
    }
}

void SetZeros::eigenApproach(Eigen::MatrixXd &matrix)
{
    int m = matrix.rows();
    int n = matrix.cols();
    bool firstRowZero = false;
    bool firstColZero = false;

    // Check if first row has zero O(n)
    for (int col = 0; col < n; col++)
    {
        if (matrix(0, col) == 0)
        {
            // Break as soon as we encounter a zero
            firstRowZero = true;
            break;
        }
    }

    // Check if first column has zero O(m)
    for (int row = 0; row < m; row++)
    {
        if (matrix(row, 0) == 0)
        {
            // Again, break as soon as we encounter a zero
            firstColZero = true;
            break;
        }
    }

    // Use first row and column to mark zeros
    for (int row = 1; row < m; row++)
    {
        for (int col = 1; col < n; col++)
        {
            // If a zero element is encountered
            if (matrix(row, col) == 0)
            {
                // Mark the entire column for zeroing
                matrix(row, 0) = 0;
                // Mark the entire row for zeroing
                matrix(0, col) = 0;
            }
        }
    }

    // Zero out cells based on marks in the first row and column
    for (int row = 1; row < m; row++)
    {
        if (matrix(row, 0) == 0)
        {
            matrix.row(row).setZero();
        }
    }

    for (int col = 1; col < n; ++col)
    {
        if (matrix(0, col) == 0)
        {
            matrix.col(col).setZero();
        }
    }

    // Zero out the first row if needed
    if (firstRowZero)
    {
        matrix.row(0).setZero();
    }

    // Zero out the first column if needed
    if (firstColZero)
    {
        matrix.col(0).setZero();
    }
}
