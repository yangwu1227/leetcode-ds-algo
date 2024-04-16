// query_sum_limit.h
#ifndef QUERY_SUM_LIMIT_H
#define QUERY_SUM_LIMIT_H
#include <vector>

/**
 * @brief Given an integer array `nums`, an array `queries` where `queries[i] = [x, y]` and an integer `limit`, return a boolean array that represents the answer to each query.
 * Each query is of the form `queries[i] = [x, y]` where `0 <= x < y < len(nums)`.
 */
class QuerySumHandler
{
public:
    /**
     * @brief This method implements the algorithm using a for loop to construct the prefix.
     *
     * @param nums An integer vector
     * @param queries A vector of vectors where `queries[i] = [x, y]`
     * @param limit An integer representing the limit
     * @return std::vector<bool> A boolean vector that represents the answer to each query
     */
    static std::vector<bool> querySumLimit(const std::vector<int> &nums, const std::vector<std::vector<int>> &queries, int limit);

    /**
     * @brief This method implements the algorithm using std::partial_sum to construct the prefix.
     *
     * @param nums An integer vector
     * @param queries A vector of vectors where `queries[i] = [x, y]`
     * @param limit An integer representing the limit
     * @return std::vector<bool> A boolean vector that represents the answer to each query
     */
    static std::vector<bool> querySumLimitOptimized(const std::vector<int> &nums, const std::vector<std::vector<int>> &queries, int limit);
};

#endif
