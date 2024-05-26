// permutation_string.cpp
#include "permutation_string.hpp"
#include <string>
#include <unordered_map>

bool checkInclusion(const std::string &s1, const std::string &s2)
{
    int s1Len = s1.size(), s2Len = s2.size();
    if (s1Len > s2Len)
    {
        return false;
    }
    std::unordered_map<char, int> s1Counts;
    std::unordered_map<char, int> s2WindowCounts;
    // O(n) where n is the length of s1
    for (int i = 0; i < s1Len; i++)
    {
        auto s1Result = s1Counts.try_emplace(s1[i], 1);
        auto s2Result = s2WindowCounts.try_emplace(s2[i], 1);
        if (!s1Result.second)
        {
            s1Result.first->second++;
        }
        if (!s2Result.second)
        {
            s2Result.first->second++;
        }
    }

    // O(m) where m = s2.size() - s1.size()
    for (int windowEnd = s1Len; windowEnd < s2Len; windowEnd++)
    {
        // O(n) average
        if (s1Counts == s2WindowCounts)
        {
            return true;
        }
        // Add the next character or increment its count if already exists
        s2WindowCounts[s2[windowEnd]]++;
        // To keep the window fixed to len(s1), decrement the count of the element at (i - len(s1))
        int windowStart = windowEnd - s1Len;
        s2WindowCounts[s2[windowStart]]--;
        // If the count of `s2[windowStart]` reaches zero, delete the key so the comparison is more efficient
        if (s2WindowCounts[s2[windowStart]] == 0)
        {
            s2WindowCounts.erase(s2[windowStart]);
        }
    }
    // Last comparison is needed since the == check happens before inserting, incrementing, decrementing counts
    // The last iteration of the loop finished without comparing the last window of length len(s1) in s2
    return s1Counts == s2WindowCounts;
}
