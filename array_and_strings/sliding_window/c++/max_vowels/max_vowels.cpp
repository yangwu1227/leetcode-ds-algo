// max_vowels.cpp
#include "max_vowels.h"
#include <string>
#include <limits.h>
#include <vector>

int maxVowels(const std::string &s, int k)
{
    int vowelCount = 0, left = 0;
    // Initialize all values to false
    bool isVowel[CHAR_MAX] = {false};
    std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    // This is O(z) where z is the number of vowels we need to check
    for (const auto &value : vowels)
    {
        isVowel[value] = true;
    }

    // First window of size k
    for (int right = 0; right < k; right++)
    {
        // If a vowel, add to counter
        if (isVowel[s[right]])
        {
            vowelCount++;
        }
    }
    // After the first window, update the answer
    int ans = vowelCount;
    for (int right = k; right < s.size(); right++)
    {
        // If a vowel, add to counter
        if (isVowel[s[right]])
        {
            vowelCount++;
        }
        // Remove element, and if the removed element is a vowel, decrement the counter
        if (isVowel[s[left]])
        {
            vowelCount--;
        }
        // Increment the left pointer to slide the window right
        left++;
        // Check if the current vowel count is greater than the previous
        ans = std::max(ans, vowelCount);
    }

    return ans;
}
