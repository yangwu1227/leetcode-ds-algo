// palindrome.cpp
#include "palindrome.h"

bool checkIfPalindrome(const std::string &s)
{
    int leftIndex = 0;
    int rightIndex = s.size() - 1;

    while (leftIndex < rightIndex)
    {
        if (s[leftIndex] != s[rightIndex])
        {
            return false;
        }
        leftIndex++;
        rightIndex--;
    }

    return true;
}
