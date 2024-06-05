// longest_substring_repeated.hpp
#ifndef LONGEST_SUBSTRING_REPEATED_HPP
#define LONGEST_SUBSTRING_REPEATED_HPP
#include <string>

class LongestSubstringRepeated
{
public:
    /**
     * @brief Given a string `s`, find the length of the longest substring without repetaed characters. This approach uses a hash map and a sliding window.
     *
     * @param s A string contining upper or lower case english characters, digits, symbols, and spaces
     * @return int Length of the longest valid subarray
     */
    static int hashMap(const std::string &s);
    /**
     * @brief Given a string `s`, find the length of the longest substring without repetaed characters. This approach uses the hash map slightly different;
     * it stores the indices of each occurrence of characters to allow the left pointer to skip.
     *
     * @param s A string contining upper or lower case english characters, digits, symbols, and spaces
     * @return int Length of the longest valid subarray
     */
    static int slidingWindowOptimized(const std::string &s);
};

#endif