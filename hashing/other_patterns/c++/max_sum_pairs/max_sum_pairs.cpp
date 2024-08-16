// max_sum_pairs.cpp
#include "max_sum_pairs.hpp"
#include "sum_digits.hpp"
#include <vector>
#include <unordered_map>

int sumDigits(int integer)
{
    int sum = 0;
    while (integer != 0)
    {
        // Use integer % 10 to extract the last digit
        sum += integer % 10;
        // Remove the last digit via integer division
        integer /= 10;
    }
    return sum;
}

int maxSum(const std::vector<int> &nums)
{
    int ans = 0;
    std::unordered_map<int, int> hashMap;
    // O(n x k) where k is the average number of digits in an integer element
    for (int num : nums)
    {
        // Compute sum of all digits
        int digitSum = sumDigits(num);
        // If this digit sum has been seen before
        if (hashMap.find(digitSum) != hashMap.end())
        {
            // Update the answer if needed
            ans = std::max(ans, num + hashMap[digitSum]);
        }
        // If the current 'num' is larger than the previous 'num' with the same digit sum, update to use this current number as the new reference for future sums
        hashMap[digitSum] = std::max(hashMap[digitSum], num);
    }

    return (ans ? ans : -1);
}