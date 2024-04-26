// check_if_pangram.cpp
#include "check_if_pangram.hpp"
#include <string>
#include <unordered_set>

bool checkIfPangram(const std::string &sentence)
{
    std::unordered_set charSet(sentence.begin(), sentence.end());
    return charSet.size() == 26;
}
