// main.cpp
#include "matrix_pattern.hpp"
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <iomanip>

void printMatrix(const std::vector<std::vector<int>> &matrix)
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

int main()
{
    using IntMatrix = std::vector<std::vector<int>>;
    using StringVector = std::vector<std::string>;
    using TestCases = std::map<IntMatrix, StringVector>;

    TestCases testCases = {
        // Test board 1
        {
            {{1, 2, 2},
             {2, 2, 3},
             {2, 3, 3}},
            {"ab", "bb"}},
        // Test board 2
        {
            {{1, 1, 2},
             {3, 3, 4},
             {6, 6, 6}},
            {"ab", "66"}},
        // Test board 3
        {
            {{1, 2},
             {2, 1}},
            {"xx"}},
        // Test board 4
        {
            {{1, 2, 3, 4},
             {5, 6, 1, 2},
             {3, 4, 5, 6},
             {7, 8, 9, 1}},
            {"12", "34"}},
        // Test board 5
        {
            {{5, 5, 5, 5, 5},
             {5, 1, 2, 3, 5},
             {5, 4, 5, 6, 5},
             {5, 7, 8, 9, 5},
             {5, 5, 5, 5, 5}},
            {"12", "45"}}};

    for (const auto &[board, pattern] : testCases)
    {
        std::cout << "Board:" << '\n';
        printMatrix(board);

        std::cout << "Pattern vector:" << '\n';
        std::cout << "{";
        for (const auto &str : pattern)
        {
            std::cout << str << (&str != &pattern.back() ? ", " : "");
        }
        std::cout << "}" << '\n';

        MatrixPattern matrixPattern = MatrixPattern(board, pattern);
        std::vector<int> indices = matrixPattern.findIndices();
        std::cout << "Indices:" << '\n';
        std::cout << "{";
        for (const auto &index : indices)
        {
            std::cout << index << (&index != &indices.back() ? ", " : "");
        }
        std::cout << "}" << '\n';
    }
    std::cout << std::endl;

    return 0;
}
