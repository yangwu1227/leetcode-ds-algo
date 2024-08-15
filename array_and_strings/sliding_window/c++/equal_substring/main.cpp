// main.cpp
#include "equal_substring.hpp"
#include <string>
#include <iostream>
#include <boost/range/combine.hpp>
#include <vector>

int main()
{
    // Test cases
    std::vector<std::string> testS = {"abcd", "abcd", "abcd"};
    std::vector<std::string> testT = {"bcdf", "cdef", "acde"};
    std::vector<int> testMaxCosts = {3, 3, 1};

    for (const auto &zipped : boost::combine(testS, testT, testMaxCosts))
    {
        std::string s;
        std::string t;
        int maxCost;
        boost::tie(s, t, maxCost) = zipped;

        int windowLen = equalSubstring(s, t, maxCost);
        std::cout << "Given the input s = " << s << ", t = " << t << ", and max cost = " << maxCost << ", the the maximum length of a substring of 's'"
                                                                                                      "that can be changed to be the same as the corresponding substring of 't' with a cost less than or equal is "
                  << windowLen << '\n';
    }
    std::cout << std::endl;

    return 0;
}
