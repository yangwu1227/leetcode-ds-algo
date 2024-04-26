// missing_number.cpp
#include "missing_number.hpp"
#include <vector>
#include <numeric> // For std::accumulate
#include <boost/range/algorithm_ext/push_back.hpp>
#include <boost/range/irange.hpp> // For boost::irange
#include <unordered_set>

// Definition for setApproach
int MissingNumber::setApproach(const std::vector<int> &nums)
{
    // Construct set, costing O(n)
    std::unordered_set numSet(nums.begin(), nums.end());
    // Check from 0 to n, if any number is missing
    for (std::size_t i = 0; i < nums.size() + 1; ++i)
    {
        // If find returns the iterator pointing at the end iterator, it is missing
        if (numSet.find(i) == numSet.end())
        {
            return i;
        }
    }

    return -1;
}

// Definition of summationApproach
int MissingNumber::summationApproach(const std::vector<int> &nums)
{
    int n = nums.size();
    int expectedSum = (n * (n + 1) / 2);
    // This is O(n) time
    int actualSum = std::accumulate(nums.begin(), nums.end(), std::vector<int>::value_type(0));
    return expectedSum - actualSum;
}

// Definition of xorAccumulateApproach
int MissingNumber::xorAccumulateApproach(const std::vector<int> &nums)
{
    int n = nums.size();
    // Vector for the range of numbers from 0 to n, inclusive
    std::vector<int> fullRange;
    boost::push_back(fullRange, boost::irange(0, n + 1));

    // Compute the XOR of all elements in the original vector
    int numXor = std::accumulate(nums.begin(), nums.end(), 0, [](int x, int y)
                                 { return x ^ y; });
    // Compute the XOR of all elements in the full range
    int rangeXor = std::accumulate(fullRange.begin(), fullRange.end(), 0, [](int x, int y)
                                   { return x ^ y; });

    // XOR the two results to find the missing number
    return numXor ^ rangeXor;
}
