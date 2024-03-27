// reverse_string.cpp
#include <vector>
#include "reverse_string.h"

void reverseString(std::vector<char> &s)
{
    int leftIndex = 0, rightIndex = s.size() - 1;
    // Loop goes until left_index becomes greater than right_index, because we have reached the middle of the array and we don't need to swap anymore
    while (leftIndex < rightIndex)
    {
        // Alternatively, std::swap(s[leftIndex], s[rightIndex]);
        std::iter_swap(s.begin() + leftIndex, s.begin() + rightIndex);
        // Move pointers towards each other
        leftIndex++;
        rightIndex--;
    }
}
