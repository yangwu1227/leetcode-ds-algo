// main.cpp
#include "row_column_pairs.hpp"
#include <iostream>
#include <vector>

int main()
{
    // Test cases
    std::vector<std::vector<std::vector<int>>> testGrids = {
        {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}},
        {{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}},
        {{1}},
        {{11, 1}, {1, 11}}};

    for (const auto &grid : testGrids)
    {
        int numEqualPairs = EqualPairs::vectorApproach(grid);
        std::cout << "Give the grid {";
        for (const auto &row : grid)
        {
            std::cout << "{";
            for (const auto &num : row)
            {
                std::cout << num << (&num != &row.back() ? ", " : "");
            }
            std::cout << "}" << (&row != &grid.back() ? ", " : "");
        }
        std::cout << "}, there are " << numEqualPairs << " equal pairs (r_i, c_i)" << '\n';
    }
    std::cout << std::endl;

    return 0;
}