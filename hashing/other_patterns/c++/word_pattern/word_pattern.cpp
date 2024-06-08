// word_pattern.cpp
#include "word_pattern.hpp"
#include "split_words.hpp"
#include <unordered_map>
#include <string>
#include <vector>
#include <boost/range/combine.hpp>                   // For boost::combine and boost:tie
#include <sstream>                                   // For std::istringstream
#include <boost/algorithm/string/classification.hpp> // For boost::is_any_of
#include <boost/algorithm/string/split.hpp>          // For boost::split

std::vector<std::string> splitWords(const std::string &s, bool boost)
{
    // Split 's' into a vector of std::string
    std::vector<std::string> words;
    if (boost)
    {
        // The boost::token_compress_on is defensive to ensure that adjacent white spaces are merged together
        boost::split(words, s, boost::is_any_of(" "), boost::token_compress_on);
    }
    else
    {
        // In the context of istringstream, a word is defined as a sequence of characters separated by whitespace (spaces, tabs, newlines, etc.)
        std::istringstream iss(s);
        std::string word;

        // Extract words using stringstream, extraction operator (>>) automatically skips any leading whitespace and reads characters until the next whitespace character is encountered
        while (iss >> word)
        {
            words.push_back(word);
        }
    }
    return words;
}

bool wordPattern(const std::string &pattern, const std::string &s, bool boost)
{
    // O(n) where n is the length of 's'
    std::vector<std::string> words = splitWords(s, boost);

    if (words.size() != pattern.size())
    {
        return false;
    }
    std::unordered_map<char, std::string> pattern2word;
    std::unordered_map<std::string, char> word2pattern;
    for (const auto &tuple : boost::combine(pattern, words))
    {
        char patChar;
        std::string word;
        boost::tie(patChar, word) = tuple;

        // If patChar already has an associated word
        if (pattern2word.find(patChar) != pattern2word.end())
        {
            // Check if patChar is associated with the current word
            if (pattern2word[patChar] != word)
            {
                // If not, it means that the same pattern character is associated with two different words, making it impossible for 's' to follow 'pattern'
                return false;
            }
        }
        // If patChar is not yet associated with any word, check if the current word is already associated with another patChar
        else if (word2pattern.find(word) != word2pattern.end())
        {
            // If so, check if the current word is associated with patChar
            if (word2pattern[word] != patChar)
            {
                // If not, it means that two different patChar are associated with this current word, making it impossible for 's' to follow 'pattern'
                return false;
            }
        }
        else
        {
            pattern2word[patChar] = word;
            word2pattern[word] = patChar;
        }
    }

    return true;
}