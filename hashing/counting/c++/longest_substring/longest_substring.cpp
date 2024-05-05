// longest_substring.cpp
#include "longest_substring.hpp"
#include <string>
#include <unordered_map>

int longestSubstring(const std::string &s, const int k)
{
    int left = 0, windowLen = 0;
    std::unordered_map<char, int> counts;
    for (int right = 0; right < s.size(); right++)
    {
        // [] automatically inserts the key with a default value (0 for integers) if it doesn't exist
        char rightChar = s[right];
        counts[rightChar]++;

        // Check if the current window has become invalid (i.e. > k distinct characters)
        while (counts.size() > k)
        {
            // Decrement the counter of the key pointed to by the left pointer
            char leftChar = s[left];
            counts[leftChar]--;
            // Check if the count has reached zero, if so, remove the key
            if (counts[leftChar] == 0)
            {
                counts.erase(leftChar);
            }
            left++;
        }
        windowLen = std::max(windowLen, right - left + 1);
    }

    return windowLen;
}
