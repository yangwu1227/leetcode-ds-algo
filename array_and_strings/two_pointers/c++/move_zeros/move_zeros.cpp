// move_zeros.cpp
#include "move_zeros.hpp"
#include <vector>

void moveZeros(std::vector<int> &nums)
{
    // Initialize the last non-zero index to 0, even if the first element is a zero, the second if statement belong avoids unnecessary swaps
    int lastNonZeroFoundAt = 0;

    // Index-based loop since we need to use the index i to reduce unnecessary swaps
    for (int i = 0; i < nums.size(); i++)
    {
        // If the current element is non-zero, we need to make a swap to bring the non-zero integer forward and push the zero element back
        if (nums[i] != 0)
        {
            // Only swap if the current integer is not the last found non-zero integer (i.e. no need to swap an element with itself)
            if (i != lastNonZeroFoundAt)
            {
                std::swap(nums[i], nums[lastNonZeroFoundAt]);
            }
            // Increment to the next non-zero element, again, this is not actually necessarily a non-zero, but the if block above prevents unnecessary swaps
            lastNonZeroFoundAt++;
        }
    }
}
