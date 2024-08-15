// is_subsequence.cpp
#include <string>
#include "is_subsequence.hpp"

bool isSubsequence(const std::string &s, const std::string &t)
{
    int sIndex = 0, tIndex = 0;

    // # The loop completes when we have checked every single character in s or t
    while (sIndex < s.size() & tIndex < t.size())
    {
        if (s[sIndex] == t[tIndex])
        {
            // Found a match in t, increment to move on to the next character in s
            sIndex++;
        }

        // Increment tIndex at every interation so the loop does not run infinitely
        tIndex++;
    }

    // We have found all characters in s in t if sIndex is at the end of 's', otherwise not
    return sIndex == s.size();
}
