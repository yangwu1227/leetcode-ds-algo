// main.cpp
#include "matrix_sum_query.hpp"
#include <vector>
#include <unordered_map>
#include <iostream>

void printQueries(const std::vector<std::vector<int>> &queries)
{
    std::cout << "Queries: " << std::endl;
    for (const auto &query : queries)
    {
        std::cout << "{";
        for (size_t i = 0; i < query.size(); ++i)
        {
            std::cout << query[i];
            if (i < query.size() - 1)
                std::cout << ", ";
        }
        std::cout << "}" << std::endl;
    }
}

int main()
{
    std::unordered_map<int, std::vector<std::vector<int>>> testCases = {
        {3, {{0, 0, 4}, {0, 1, 2}, {1, 0, 1}, {0, 2, 3}, {1, 2, 5}}},
        {4, {{0, 0, 1}, {1, 2, 2}, {0, 2, 3}, {1, 0, 4}}},
        {static_cast<int>(std::pow(10, 5)), {{0, 8000, 4}, {1, static_cast<int>(std::pow(10, 2)), 12}, {1, 3435, 27}, {0, 4, 77}, {0, static_cast<int>(std::pow(7, 2)), 17}}}};

    for (const auto &[n, queries] : testCases)
    {
        long long matrixSumEfficient = MatrixSumQueries::efficient(n, queries);
        std::cout << "Matrix size: " << n << '\n';
        printQueries(queries);
        std::cout << "Matrix sum: " << matrixSumEfficient << '\n';
        std::cout << '\n';

    }
    std::cout << std::endl;

    return 0;
}
