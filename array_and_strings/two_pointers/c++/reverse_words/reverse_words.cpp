// reverse_words.cpp
#include "reverse_words.hpp"
#include <string>
#include <boost/algorithm/string.hpp>
#include <vector>

// Definition of reverseWordsLoop
void WordReverser::reverseWordsLoop(std::string &s)
{
    // Stores the index of space character we most recently reached, initialized to -1
    int mostRecentSpaceIndex = -1;
    int n = s.size();

    // Traverse the entire string 0 to n - 1
    for (int strIndex = 0; strIndex <= n; strIndex++)
    {
        // The if block runs if we have reached a space character or if we are at the end of the string 's'
        if (strIndex == n || s[strIndex] == ' ')
        {
            // Start of the word index (the very first iteration leftIndex will be -1 + 1 = 0)
            int leftIndex = mostRecentSpaceIndex + 1;
            // End of the word index, which is one before the current strIndex that points at a particular space character
            int rightIndex = strIndex - 1;

            while (leftIndex < rightIndex)
            {
                // Swap the characters and move pointers towards each other
                std::swap(s[leftIndex], s[rightIndex]);
                leftIndex++;
                rightIndex--;
            }
            // Before the current iteration ends, update 'mostRecentSpaceIndex' to the index of the current space character
            mostRecentSpaceIndex = strIndex;
        }
    }
}

// Definition of reverseWordsBoost
std::string WordReverser::reverseWordsBoost(std::string s)
{
    // Split string into a vector of words
    std::vector<std::string> vecOfWords;
    // Use token_compress_on if there's consecutive separators
    boost::split(vecOfWords, s, boost::is_any_of(" "), boost::token_compress_on);

    // Iterate through each word and reverse it
    for (auto &word : vecOfWords)
    {

        int leftIndex = 0;
        int rightIndex = word.size() - 1;

        // Loop ends when the two pointers meet in the middle
        while (leftIndex < rightIndex)
        {
            // Use std::iter_swap to swap characters
            std::iter_swap(word.begin() + leftIndex, word.begin() + rightIndex);
            leftIndex++;
            rightIndex--;
        }
    }

    // Join the vector of words into a single string
    std::string result = boost::algorithm::join(vecOfWords, " ");
    return result;
}
