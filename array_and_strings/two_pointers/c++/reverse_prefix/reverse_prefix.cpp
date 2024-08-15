// reverse_prefix.cpp
#include "reverse_prefix.hpp"
#include <string>

std::string reversePrefix(std::string &word, const char &ch)
{
    // Find first occurrence of ch in word
    std::size_t chIndex = word.find_first_of(ch);
    if (chIndex == std::string::npos)
    {
        return word;
    }

    int leftIndex = 0, rightIndex = chIndex;
    while (leftIndex < rightIndex)
    {
        // Swap and move pointers towards each other
        std::iter_swap(word.begin() + leftIndex, word.begin() + rightIndex);
        leftIndex++;
        rightIndex--;
    }

    return word;
}
