// two_sum.hpp
#ifndef TWO_SUM_HPP
#define TWO_SUM_HPP
#include <vector>

class Solution
{
public:
    /**
     * @brief Given an array of integers `nums` and an integer `target`, return indices of two numbers such that they add up to `target`. We cannot use
     * the same index twice. This method does two passes: once to build the hash map and once to check if the complement (`target - num`) exists.
     *
     * @param nums A vector of integers (unsorted)
     * @param target A positive integer
     * @return std::vector<int> The indices of two numbers that sum up to `target`
     */
    static std::vector<int> twoPassesTwoSum(const std::vector<int> &nums, int target);

    /**
     * @brief This method does a single pass to build the hash map and check if the complement (`target - num`) exists.
     *
     * @param nums A vector of integers (unsorted)
     * @param target A positive integer
     * @return std::vector<int> The indices of two numbers that sum up to `target`
     */
    static std::vector<int> onePassTwoSum(const std::vector<int> &nums, int target);
};

#endif
