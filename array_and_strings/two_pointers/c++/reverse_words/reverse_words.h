// reverse_words.h
#ifndef REVERSE_WORDS_H
#define REVERSE_WORDS_H

#include <string>

/**
 * @brief This class provides two methods for reversing the characters in each word of a sentence while still preserving whitespace and initial word order.
 */
class WordReverser
{
public:
    /**
     * @brief This method uses a for loop to split string into a vector of words.
     *
     * @param s A string containing words separated by whitespace.
     * @return std::string The string with the order of characters in each word reversed.
     */
    static void reverseWordsLoop(std::string &s);

    /**
     * @brief This method uses the boost split function to split string into a vector of words.
     * Then uses join to combine the vector of reversed words back into a string.
     *
     * @param s A string containing words separated by whitespace.
     * @return std::string The string with the order of characters in each word reversed.
     */
    static std::string reverseWordsBoost(std::string s);
};

#endif
