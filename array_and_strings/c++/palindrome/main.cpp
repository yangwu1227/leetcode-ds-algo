// main.cpp
#include <iostream>
#include <string> // Explicitly include string, even if the header file already includes it
#include <vector>
#include "palindrome.h"

int main()
{
    std::vector<std::string> testStrings = {"racecar", "soccer"}; // Vector of strings to test

    // Pass by reference, immutable
    for (const std::string &testString : testStrings)
    {
        bool isPalindrome = checkIfPalindrome(testString);

        if (isPalindrome)
        {
            std::cout << testString << " is a palindrome." << std::endl;
        }
        else
        {
            std::cout << testString << " is not a palindrome." << std::endl;
        }
    }

    return 0;
}
