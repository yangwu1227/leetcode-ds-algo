// query_sum_limit.cpp
#include "query_sum_limit.hpp"
#include <vector>
#include <numeric> // For partial_sum

// Definition of first implementation
std::vector<bool> QuerySumHandler::querySumLimit(const std::vector<int> &nums, const std::vector<std::vector<int>> &queries, const int limit)
{
    if (nums.empty())
        return {};

    // Build prefix array
    std::vector<int> prefix = {nums[0]};
    for (int i = 1; i < nums.size(); i++)
    {
        // The value prefix.back() is the sum up to and including the (i - 1)th element, to which we add the ith element
        prefix.push_back(prefix.back() + nums[i]);
    }

    // Build the solution
    std::vector<bool> ans;
    ans.reserve(queries.size());
    for (const auto &query : queries)
    {
        int left = query[0], right = query[1];
        int subarraySum = prefix[right] - prefix[left] + nums[left];
        ans.push_back(subarraySum < limit);
    }

    return ans;
}

// Definition of optimized implementation
std::vector<bool> QuerySumHandler::querySumLimitOptimized(const std::vector<int> &nums, const std::vector<std::vector<int>> &queries, const int limit)
{
    if (nums.empty())
        return {};

    // Build prefix using partial sum
    std::vector<int> prefix(nums.size());
    // The arguments are first, last, and result (i.e. destination vector)
    std::partial_sum(nums.begin(), nums.end(), prefix.begin());

    std::vector<bool> ans;
    ans.reserve(queries.size());
    for (const auto &query : queries)
    {
        int left = query[0], right = query[1];
        // Another way to compute subarray sum, if left index is 0, the prefix sum is simply prefix[right], otherwise, return prefix[right] - prefix[left - 1]
        int subarraySum = prefix[right] - (left > 0 ? prefix[left - 1] : 0);
        ans.push_back(subarraySum < limit);
    }

    return ans;
}
