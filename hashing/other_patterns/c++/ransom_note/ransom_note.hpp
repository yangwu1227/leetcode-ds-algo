// ransom_note.hpp
#ifndef RANSOM_NOTE_HPP
#define RANSOM_NOTE_HPP
#include <string>

class RansomNote
{
public:
    /**
     * @brief Given two strings `ransom_note` and `magazine`, return `true` if `ransom_note` can be constructed by using the letters from `magazine`. This approach uses
     * two hash maps.
     *
     * @param ransomNote A string containing lower case english letters
     * @param magazine A string containing lower case english letters
     * @return bool `true` if `magazine` contains a permutation of `magazine`, `false` if not
     */
    static bool twoHashMaps(const std::string &ransomNote, const std::string &magazine);

    /**
     * @brief Given two strings `ransom_note` and `magazine`, return `true` if `ransom_note` can be constructed by using the letters from `magazine`. This approach uses a single
     * hash map.
     *
     * @param ransomNote A string containing lower case english letters
     * @param magazine A string containing lower case english letters
     * @return bool `true` if `magazine` contains a permutation of `magazine`, `false` if not
     */
    static bool oneHashMap(const std::string &ransomNote, const std::string &magazine);
};

#endif