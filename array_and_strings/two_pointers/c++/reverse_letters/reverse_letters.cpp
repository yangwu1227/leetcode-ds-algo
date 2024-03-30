// reverse_letters.cpp
#include "reverse_letters.h"
#include <string>

std::string reverseLetters(std::string &s)
{
    int leftIndex = 0, rightIndex = s.size() - 1;

    while (leftIndex < rightIndex)
    {
        if (std::isalpha(s[leftIndex]) & std::isalpha(s[rightIndex]))
        {
            // If both pointers point at letters, swap and move pointers towards each other
            std::iter_swap(s.begin() + leftIndex, s.begin() + rightIndex);
            leftIndex++;
            rightIndex--;
        }
        else if (!std::isalpha(s[leftIndex]))
        {
            // If left element is not a letter, increment
            leftIndex++;
        }
        else if (!std::isalpha(s[rightIndex]))
        {
            // If right element is not a letter, decrement
            rightIndex--;
        }
    }
    return s;
}
