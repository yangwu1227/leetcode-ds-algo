// longest_substring_repeated.cpp
#include "longest_substring_repeated.hpp"
#include <string>
#include <unordered_map>

int LongestSubstringRepeated::hashMap(const std::string &s)
{
    int left = 0, windowLen = 0;
    std::unordered_map<char, int> characterCounts;
    // O(2n) visits to each character
    for (int right = 0; right < s.size(); right++)
    {
        // Expand the window
        characterCounts[s[right]]++;
        // As soon as any count exceeds 1, start shrinking the window
        while (characterCounts[s[right]] > 1)
        {
            // Decrement the count of the character pointed to by the left pointer
            characterCounts[s[left]]--;
            left++;
        }
        windowLen = std::max(windowLen, right - left + 1);
    }
    return windowLen;
}

int LongestSubstringRepeated::slidingWindowOptimized(const std::string &s)
{
    int left = 0, windowLen = 0;
    std::unordered_map<char, int> characterIndices;
    // May be less than O(2n) visits to each character
    for (int right = 0; right < s.size(); right++)
    {
        // Check if s[right] is a repeat
        if (characterIndices.find(s[right]) != characterIndices.end())
        {
            // Move the left pointer to the right of the most recently seen occurrence of s[right]
            left = std::max(left, characterIndices[s[right]]);
        }
        windowLen = std::max(windowLen, right - left + 1);
        // Update the index of this character to one after the current right index (i.e. mark its latest occurrence)
        characterIndices[s[right]] = right + 1;
    }
    return windowLen;
}