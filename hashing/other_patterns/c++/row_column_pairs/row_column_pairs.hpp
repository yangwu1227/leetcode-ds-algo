// row_column_pair.hpp
#ifndef ROW_COLUMN_PAIRS_HPP
#define ROW_COLUMN_PAIRS_HPP
#include <vector>

class EqualPairs
{
public:
    /**
     * @brief Given a `n x  n` matrix of positive integers, return the number of pairs `(r_i, c_i)` such that row `r_i` and column `c_i` are equal. A row and 
     * column pair are considered equal if they contian the same elements in the same order, i.e., they are equal arrays.
     *
     * @param grid A 2-D array represnted by a vector of vectors
     * @return int Number of equal pairs
     */
    static int vectorApproach(const std::vector<std::vector<int>> &grid);
};

#endif