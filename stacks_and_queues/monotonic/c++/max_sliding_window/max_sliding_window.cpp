// max_sliding_window.cpp
#include "max_sliding_window.hpp"
#include <vector>
#include <deque>

std::vector<int> maxSlidingWindow(const std::vector<int> &nums, int k)
{
    if (nums.size() == 1)
    {
        return nums;
    }

    std::deque<int> numDeque;
    std::vector<int> output;
    output.reserve(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        // As long as the deque is non-empty and the element pointed by the last index of the deque is less than that at the current index
        while (!numDeque.empty() && nums[numDeque.back()] < nums[i])
        {
            // Pop the last index from the deque to maintining the monotonic non-increasing property
            numDeque.pop_back();
        }
        // Push the current index to the deque as long as the element it points to is smaller than the element pointed to by the back of the deque or if the deque is empty
        numDeque.push_back(i);
        // Start updating the output array once we reach the (k - 1)th element
        if (i >= k - 1)
        {
            // Check if the first index of the deque is not outside of the window
            if (numDeque.back() - numDeque.front() == k)
            {
                // Pop the front of the deque to maintain window size
                numDeque.pop_front();
            }
            // Update the output with the maximum of the current window, which is the element pointed to by the first index of the deque
            output.push_back(nums[numDeque.front()]);
        }
    }

    return output;
}
