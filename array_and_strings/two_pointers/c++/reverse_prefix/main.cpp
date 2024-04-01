// main.cpp
#include "reverse_prefix.h"
#include <string>
#include <boost/range/combine.hpp>
#include <vector>
#include <iostream>

int main()
{

    // Test Cases
    std::vector<std::string> testWords = {"abcdefd", "xyxzxe", "abcd"};
    std::vector<char> testChars = {'d', 'z', 'z'};

    for (const auto &tuple : boost::combine(testWords, testChars))
    {
        std::string word;
        char ch;
        // Unpack the tuple, which is a (word, chr) pair
        boost::tie(word, ch) = tuple;

        std::cout << "The input string '" << word << "' and character '" << ch;
        std::string result = reversePrefix(word, ch);
        std::cout << "' -> " << result << std::endl;
    }

    return 0;
}
