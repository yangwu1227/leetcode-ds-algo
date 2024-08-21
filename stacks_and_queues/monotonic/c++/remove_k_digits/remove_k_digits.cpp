// remove_k_digits.cpp
#include "remove_k_digits.hpp"
#include <string>

std::string removeKDigits(std::string &num, int k)
{
    int n = num.size();
    if (n == 1 || n == k)
    {
        return "0";
    }

    std::string output;
    // The output can at most contain n - 1 digits when k = 1
    output.reserve(n - 1);
    for (const auto &digit : num)
    {
        // While the stack is non-empty and the top of the stack is greater than the current digit
        while (!output.empty() && k > 0 && output.back() > digit)
        {
            // Pop the last digit to maintain monotonic non-decreasing property and decrement k
            output.pop_back();
            k -= 1;
        }
        // Push the current digit to back of the string
        output.push_back(digit);
    }

    // If the main loop completes without removing 'k' digits, remove the remaining digits
    while (k > 0)
    {
        output.pop_back();
        k -= 1;
    }

    // Remove any leading zero's
    output.erase(0, output.find_first_not_of('0'));

    // Return "0" if the output becomes empty after all processing, else return the output
    return !output.empty() ? output : "0";
}
