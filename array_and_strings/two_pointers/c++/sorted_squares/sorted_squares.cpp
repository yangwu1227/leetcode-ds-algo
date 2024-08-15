// sorted_squares.cpp
#include "sorted_squares.hpp"
#include <vector>

std::vector<int> sortedSquares(std::vector<int> nums)
{
    int n = nums.size();
    int leftIndex = 0, rightIndex = n - 1;

    // Initialize vector of size n with all elements as 0
    std::vector<int> result(n, 0);

    // Loop in reverse, using decrement operator
    for (int i = n - 1; i >= 0; --i)
    {
        int leftAbs = std::abs(nums[leftIndex]);
        int rightAbs = std::abs(nums[rightIndex]);
        // In c++, scope of local variable only falls within the enclosing brackets, and so we must define 'squares' outside
        int squares;
        if (leftAbs < rightAbs)
        {
            // If the right element's abs is larger, then its squared value is larger
            rightIndex--;
            squares = std::pow(rightAbs, 2);
        }
        else
        {
            // If the left element's abs is larger, its squared value is larger
            // This branch handles ties, adds the left squared and leaves right squared to next iteration
            leftIndex++;
            squares = std::pow(leftAbs, 2);
        }
        result[i] = squares;
    }

    return result;
}
