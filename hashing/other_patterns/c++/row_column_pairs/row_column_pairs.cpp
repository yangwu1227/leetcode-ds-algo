// row_column_pairs.cpp
#include "row_column_pairs.hpp"
#include "vec_to_string.hpp"
#include <map>
#include <vector>
#include <string>

std::string vecToString(const std::vector<int> &vec)
{
    std::string vecString = "";
    for (auto num : vec)
    {
        vecString += std::to_string(num) + ',';
    }
    return vecString;
}

int EqualPairs::vectorApproach(const std::vector<std::vector<int>> &grid)
{
    // Count the number of occurrences of each row
    std::unordered_map<std::string, int> rowCounts;
    for (const auto &row : grid)
    {
        // Conversion cost O(n) where n is the number of columns in grid
        std::string rowString = vecToString(row);
        auto emplaceResult = rowCounts.try_emplace(rowString, 1);
        // If key already exists
        if (!emplaceResult.second)
        {
            // Increment the count
            emplaceResult.first->second++;
        }
    }

    // Count the number of occurrences of each column
    std::unordered_map<std::string, int> columnCounts;
    for (int j = 0; j < grid[0].size(); j++)
    {
        // Build the column vector
        std::vector<int> column;
        std::transform(
            grid.begin(), grid.end(),
            // Inserter to inser each row[j] into the column vector container
            std::inserter(column, column.end()),
            [j](const auto &row)
            {
                // Extract the jth element in each row
                return row[j];
            });
        // Convert vector to string
        std::string columnString = vecToString(column);
        auto emplaceResult = columnCounts.try_emplace(columnString, 1);
        if (!emplaceResult.second)
        {
            emplaceResult.first->second++;
        }
    }

    // Iterate through each column and check if there are matching rows
    int numEqualPairs = 0;
    for (const auto &[columnString, count] : columnCounts)
    {
        numEqualPairs += count * rowCounts[columnString];
    }

    return numEqualPairs;
}