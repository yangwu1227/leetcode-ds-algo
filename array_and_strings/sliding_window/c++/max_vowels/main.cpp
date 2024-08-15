// main.cpp
#include "max_vowels.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <boost/range/combine.hpp>

int main()
{
    std::vector<std::string> testStrings = {"aoseufauaiesf", "abuiiidef", "leetcodeisterribleformentalhealth"};
    std::vector<int> testK = {6, 4, 5};

    for (const auto &zipped : boost::combine(testStrings, testK))
    {
        std::string s;
        int k;
        boost::tie(s, k) = zipped;

        int ans = maxVowels(s, k);
        std::cout << "Give the input string " << s << " and k = " << k << ", the maximum number of vowels in any subarray of length " << k << " is " << ans << '\n';
    }
    std::cout << std::endl;

    return 0;
}
