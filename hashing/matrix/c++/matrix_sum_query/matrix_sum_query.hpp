// matrix_sum_query.hpp
#ifndef MATRIX_SUM_QUERY_HPP
#define MATRIX_SUM_QUERY_HPP
#include <vector>

/**
 * @class MatrixSumQueries
 *
 * @brief Given an integer `n` and a 0-indexed 2D array queries where `queries[i] = [type_i, index_i, val_i]`. Initially, all values of the `n x n` matrix are
 * initialized to 0's. Then, return the sum of the matrix after all queries are applied.
 *
 * @note If `type_i == 0`, set the values in the row with `index_i` to `val_i`, overwriting any previous values
 * @note If `type_i == 1`, set the values in the column with `index_i` to `val_i`, overwriting any previous values
 *
 *
 * @param n The size of the matrix
 * @param queries A vector of queries
 * @return int The sum of the matrix after applying all queires
 */
class MatrixSumQueries
{
public:
    static long long efficient(int n, const std::vector<std::vector<int>> &queries);
};

#endif
