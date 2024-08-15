// equal_substring.cpp
#include "equal_substring.hpp"
#include <string>

int equalSubstring(const std::string &s, const std::string &t, const int maxCost)
{
    int cost = 0, left = 0, windowLen = 0;
    // Since s and t have the same length
    for (int right = 0; right < s.size(); right++)
    {
        // Cost of swapping s[right] and t[right]
        cost += std::abs(int(s[right]) - int(t[right]));
        // Check if the current window has become invalid, i.e. cost > maxCost
        while (cost > maxCost)
        {
            // Remove elements from the left and their respective costs of swapping
            cost -= std::abs(int(s[left]) - int(t[left]));
            // Slide the window towards the right
            left++;
        }
        // Check if the current window is greater than the previous
        windowLen = std::max(windowLen, right - left + 1);
    }
    return windowLen;
}
