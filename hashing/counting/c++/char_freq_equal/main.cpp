// main.cpp
#include "char_freq_equal.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <cassert>

int main()
{
    std::vector<std::string> testStrings = {"aaabb", "ababcdca", "dzdzrtsfrfst"};
    for (const auto &s : testStrings)
    {
        bool setAns = CharFrequency::setApproach(s);
        bool earlyReturnAns = CharFrequency::earlyReturnApproach(s);
        bool lambdaAns = CharFrequency::lambdaApproach(s);
        bool minMaxAns = CharFrequency::minMaxApproach(s);
        assert((setAns == earlyReturnAns) && (earlyReturnAns == lambdaAns) && (lambdaAns == minMaxAns));

        std::cout << "Given the string " << s << ", all characters " << (minMaxAns ? "have" : "do not have") << " the same number of occurrences" << '\n';
    }
    std::cout << std::endl;

    return 0;
}
