// max_number_target_word.hpp
#ifndef MAX_NUMBER_TARGET_WORD_HPP
#define MAX_NUMBER_TARGET_WORD_HPP
#include <string>

class MaxNumberTargetWord
{
public:
    /**
     * @brief Given a string `text`, use the characters of `text` to form as many instances of the word ``targetWord`` as possible.
     *
     * @param text A string containing lower case english letters
     * @param targetWord A target word
     * @return int The maximum number of instances of the word ``targetWord`` that can be formed
     *
     * @note  Note: Use each character in text at most once.
     */
    static int loop(const std::string &text, const std::string &targetWord);

    /**
     * @brief Given a string `text`, use the characters of `text` to form as many instances of the word ``targetWord`` as possible. This method uses `std::transform_reduce`
     * to find the maximum number of instances of `targetWord` we can form.
     *
     * @param text A string containing lower case english letters
     * @param targetWord A target word
     * @return int The maximum number of instances of the word ``targetWord`` that can be formed
     *
     * @note  Note: Use each character in text at most once.
     */
    static int transformReduce(const std::string &text, const std::string &targetWord);
};

#endif
