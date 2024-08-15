// reverse_word_order.cpp
#include "reverse_word_order.hpp"
#include <vector>
#include <algorithm>                  // For std::reverse
#include <sstream>                    // For std::istringstream
#include <boost/algorithm/string.hpp> // For boost::algorithm::join

std::string reverseWordOrder(std::string &s, bool useBoostJoin)
{
    // Vector of words
    std::vector<std::string> words;
    // In the context of istringstream, a word is defined as a sequence of characters separated by whitespace (spaces, tabs, newlines, etc.)
    std::istringstream iss(s);
    std::string word;

    // Extract words using stringstream, extraction operator (>>) automatically skips any leading whitespace and reads characters until the next whitespace character is encountered
    while (iss >> word)
    {
        words.push_back(word);
    }

    // Reverse the vector of words, in-place
    std::reverse(words.begin(), words.end());

    // Join the words into a single string, or we could use 'boost::algorithm::join(words, " ");'
    if (useBoostJoin)
    {
        return boost::algorithm::join(words, " ");
    }
    else
    {
        std::string reversed;
        for (int i = 0; i < words.size(); ++i)
        {
            reversed += words[i];
            // Add a space between words, but not after the last word
            if (i < words.size() - 1)
            {
                reversed += " ";
            }
        }
        return reversed;
    }
}
