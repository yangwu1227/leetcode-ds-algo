#include "max_ones_single_flip.h"
#include <string>

int findLength(const std::string &s)
{
    int left = 0, currZeroCount = 0, windowLen = 0;
    for (int right = 0; right < s.size(); right++)
    {
        // If the current element the right pointer points to is zero, add the the counter
        // We have one chance to flip a 0 to 1, but we need to note down that we have encountered a 0
        if (s[right] == '0')
        {
            currZeroCount++;
        }
        // If the window becomes invalid (i.e., we have encountered more than 1 0's we cannot flip)
        while (currZeroCount > 1)
        {
            // If the element the left pointer points to is zero, we can reduce the counter because we have removed it by shrinking the window
            if (s[left] == '0')
            {
                currZeroCount--;
            }
            // Increment the left pointer to slide the window towards the right
            left++;
        }

        windowLen = std::max(windowLen, right - left + 1);
    }

    return windowLen;
}
