// main.cpp
#include <string>
#include <iostream>
#include <vector>
#include <tuple> // Include for std::tuple
#include "is_subsequence.h"

int main()
{

    // Test cases as a vector of tuples (s, t)
    std::vector<std::tuple<std::string, std::string>> testCases = {{"yang", "yasdndfdfg"}, {"wu", "wdfkjsdknfdfj"}};

    // Iterate through each test case pairs
    for (const auto &testCase : testCases)
    {
        // Use std::get (index-based) to access tuple elements
        const std::string &s = std::get<0>(testCase);
        const std::string &t = std::get<1>(testCase);

        std::cout << "The string " << s << (isSubsequence(s, t) ? " is " : " is not ") << "a subsequence of " << t << std::endl;
    }

    return 0;
}
