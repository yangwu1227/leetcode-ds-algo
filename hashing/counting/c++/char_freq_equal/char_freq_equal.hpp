// char_freq_equal.hpp
#ifndef CHAR_FREQ_EQUAL_HPP
#define CHAR_FREQ_EQUAL_HPP
#include <string>

class CharFrequency
{
public:
    /**
     * @brief Given a string `s`, determine if all characters have the same frequency. This method uses a hash map and then a hash set, checking if
     * the final set contains only one element, i.e. all counts are the same for all characters.
     *
     * @param s A std::string consisting of english letters
     * @return bool true if all characters have the same number of occurrences otherwise false
     */
    static bool setApproach(const std::string &s);

    /**
     * @brief Given a string `s`, determine if all characters have the same frequency. This method uses `std::all_of`, which checks if a
     * unary predicate `p` (a lambda function that compares each character's count to the first character's count) returns `true` for all elements
     * in the hash map.
     *
     * @param s A std::string consisting of english letters
     * @return bool true if all characters have the same number of occurrences otherwise false
     */
    static bool lambdaApproach(const std::string &s);

    /**
     * @brief Given a string `s`, determine if all characters have the same frequency. This method uses `std::minmax_element`, which finds the
     * min and max counts in the hash map. Then, it compares the min and max, returning `true` if they are the same otherwise `false`.
     *
     * @param s A std::string consisting of english letters
     * @return bool true if all characters have the same number of occurrences otherwise false
     */
    static bool minMaxApproach(const std::string &s);

    /**
     * @brief Given a string `s`, determine if all characters have the same frequency. Because we only need to return a boolean, we can return
     * early as soon as we encounter the first pair of frequencies that differ.
     *
     * @param s A std::string consisting of english letters
     * @return bool true if all characters have the same number of occurrences otherwise false
     */
    static bool earlyReturnApproach(const std::string &s);
};

#endif
