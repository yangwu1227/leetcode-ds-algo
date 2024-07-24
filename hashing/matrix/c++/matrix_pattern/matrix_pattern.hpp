// matrix_pattern.hpp
#ifndef MATRIX_PATTERN_HPP
#define MATRIX_PATTERN_HPP
#include <vector>
#include <string>

class MatrixPattern
{
public:
    /**
     * @brief Construct a new Matrix Pattern object.
     *
     * @param board The board matrix to search for the pattern matrix in
     * @param pattern The pattern matrix to search for in the board matrix
     */
    MatrixPattern(const std::vector<std::vector<int>> &board, const std::vector<std::string> &pattern);

    /**
     * @brief Find the indices of the top left corner of the submatrix in the board matrix that matches the pattern matrix.
     *
     * @return std::vector<int> The indices of the top left corner of the submatrix in the board matrix that matches the pattern matrix, or {-1, -1} if no such submatrix exists
     */
    std::vector<int> findIndices();

private:
    std::vector<std::vector<int>> board;
    std::vector<std::string> pattern;
    int nRowsBoard;
    int nColsBoard;
    int nRowsPattern;
    int nColsPattern;

    /**
     * @brief Check if the submatrix of the board matrix starting at the top left corner (i, j) matches the pattern matrix.
     *
     * @param i The row index of the top left corner of the submatrix
     * @param j The column index of the top left corner of the submatrix
     *
     * @return bool `true` if the submatrix matches the pattern matrix, `false` otherwise
     */
    bool checkPattern(const int i, const int j);
};

#endif
