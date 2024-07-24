// matrix_pattern.cpp
#include "matrix_pattern.hpp"
#include <vector>
#include <unordered_map>
#include <string>

MatrixPattern::MatrixPattern(const std::vector<std::vector<int>> &board, const std::vector<std::string> &pattern)
{
    this->board = board;
    this->pattern = pattern;
    this->nRowsBoard = board.size();
    this->nColsBoard = board[0].size();
    this->nRowsPattern = pattern.size();      // Pattner is a vector
    this->nColsPattern = pattern[0].length(); // Each element of pattner is a std::string
}

bool MatrixPattern::checkPattern(const int i, const int j)
{
    // Bidirectional hash maps
    std::unordered_map<int, char> intBoardToStrPattern;
    std::unordered_map<char, int> strPatternToIntBoard;

    for (int rowPattern = 0; rowPattern < this->nRowsPattern; rowPattern++)
    {
        for (int colPattern = 0; colPattern < this->nColsPattern; colPattern++)
        {
            int rowBoard = i + rowPattern;
            int colBoard = j + colPattern;
            int intBoard = this->board[rowBoard][colBoard];
            char strPattern = this->pattern[rowPattern][colPattern];

            // If strPattern is a digit, check if it the same as the current board integer, if not, this submatrix cannot be valid
            if (std::isdigit(strPattern))
            {
                if (intBoard != strPattern - '0')
                {
                    return false;
                }
            }
            else
            {
                // Check if the current board integer is already mapped to a pattern string, and if it is not he same as the current string pattern, return false
                if (intBoardToStrPattern.find(intBoard) != intBoardToStrPattern.end() && intBoardToStrPattern[intBoard] != strPattern)
                {
                    return false;
                }
                // Check if the current pattern string is already mapped to by another board integer, and if it is not the same as the current board integer, return false
                if (strPatternToIntBoard.find(strPattern) != strPatternToIntBoard.end() && strPatternToIntBoard[strPattern] != intBoard)
                {
                    return false;
                }

                // Update the hash maps
                intBoardToStrPattern[intBoard] = strPattern;
                strPatternToIntBoard[strPattern] = intBoard;
            }
        }
    }
    // If we scan through all elements of the submatrix and did not return early, then this is a valid subatrix
    return true;
}

std::vector<int> MatrixPattern::findIndices()
{
    // Iterate over all submatrices
    for (int i = 0; i < (this->nRowsBoard - this->nRowsPattern + 1); i++)
    {
        for (int j = 0; j < (this->nColsBoard - this->nColsPattern + 1); j++)
        {
            if (this->checkPattern(i, j))
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}
