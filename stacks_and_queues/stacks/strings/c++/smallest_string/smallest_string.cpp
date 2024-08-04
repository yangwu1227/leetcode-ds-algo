// smallest_string.cpp
#include "smallest_string.hpp"
#include <string>
#include <deque>
#include <vector>

std::string smallestString(const std::string &s)
{
    if (s.length() == 1)
    {
        return s;
    }

    // Load all characters in 's' into a deque to make popping from the left O(1)
    std::deque<char> originalDeque(s.begin(), s.end());
    std::deque<char> tempDeque;
    std::string output;

    // Precompute the smallest characters to the right for each character in s
    // E.g., "yangwu" -> ['a', 'a', 'g', 'g', 'u', 'u']
    std::vector<char> smallestRight(s.length());
    // The smallest character to the right of the last character of 's' is always s[-1]
    smallestRight.back() = s.back();
    // Start with second to last character in 's' going from right to left
    for (int i = s.length() - 2; i >= 0; --i)
    {
        smallestRight[i] = std::min(s[i], smallestRight[i + 1]);
    }

    // As long as one of StackS or StackT is not empty
    while (!originalDeque.empty() || !tempDeque.empty())
    {
        // If tempDeque is not empty and (either originalDeque is empty or 
        // The last character of tempDeque is <= the smallest character in originalDeque to the right of the current position)
        if (!tempDeque.empty() && (originalDeque.empty() || tempDeque.back() <= smallestRight[s.length() - originalDeque.size()]))
        {
            output.push_back(tempDeque.back());
            tempDeque.pop_back();
        }
        else
        {
            // Otherwise, move the first character from originalDeque to tempDeque
            tempDeque.push_back(originalDeque.front());
            originalDeque.pop_front();
        }
    }

    return output;
}
