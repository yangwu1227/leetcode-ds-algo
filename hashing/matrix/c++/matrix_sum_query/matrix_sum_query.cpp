// matrix_sum_query.cpp
#include "matrix_sum_query.hpp"
#include <unordered_set>
#include <vector>

long long MatrixSumQueries::efficient(int n, const std::vector<std::vector<int>> &queries)
{
    long long matrixSum = 0;
    std::unordered_set<int> visitedColumns;
    std::unordered_set<int> visitedRows;
    int verticalCellsLeftToModify = n;
    int horizontalCellsLeftToModify = n;

    // Use reverse iterator to start from the last query
    for (auto it = queries.rbegin(); it != queries.rend(); ++it)
    {
        int typeCol = (*it)[0];
        int index = (*it)[1];
        int val = (*it)[2];

        // If type == 1 and this column has not been visited already
        if (typeCol && visitedColumns.find(index) == visitedColumns.end())
        {
            matrixSum += val * verticalCellsLeftToModify;
            horizontalCellsLeftToModify -= 1;
            visitedColumns.insert(index);
        }
        // If type == 0 and this row has not been visited already
        else if (!typeCol && visitedRows.find(index) == visitedRows.end())
        {
            matrixSum += val * horizontalCellsLeftToModify;
            verticalCellsLeftToModify -= 1;
            visitedRows.insert(index);
        }
    }
    return matrixSum;
}
