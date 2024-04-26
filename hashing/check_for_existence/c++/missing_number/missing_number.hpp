// missing_number.hpp
#ifndef MISSING_NUMBER_HPP
#define MISSING_NUMBER_HPP
#include <vector>

class MissingNumber
{
public:
    /**
     * @brief Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return the only number in the range that is missing from the array. This
     * static method uses the set approach.
     *
     * @param nums A sequence of `n` numbers 
     * @return The missing number in the range `[0, n]`
     */
    static int setApproach(const std::vector<int> &nums);

    /**
     * @brief Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return the only number in the range that is missing from the array. This
     * static method uses the summation formula.
     *
     * @param nums A sequence of `n` numbers 
     * @return The missing number in the range `[0, n]`
     */
    static int summationApproach(const std::vector<int> &nums);

    /**
     * @brief Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return the only number in the range that is missing from the array. This
     * static method uses XOR and accumulate to find the missing number.
     *
     * @param nums A sequence of `n` numbers 
     * @return The missing number in the range `[0, n]`
     */
    static int xorAccumulateApproach(const std::vector<int> &nums);
};

#endif
