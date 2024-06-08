// isomorphic_strings.cpp
#include "isomorphic_strings.hpp"
#include <string>
#include <unordered_map>
#include <boost/range/combine.hpp>

bool isomorphic(const std::string &s, const std::string &t)
{
    std::unordered_map<char, char> s2tMap;
    std::unordered_map<char, char> t2sMap;
    for (const auto &tuple : boost::combine(s, t))
    {
        // Unpack
        char charS, charT;
        boost::tie(charS, charT) = tuple;

        // Check I: if charS is already mapped to a character in t
        if (s2tMap.find(charS) != s2tMap.end())
        {
            // If charS has a mapping, check if it is mapped to a the same character as the current charT
            if (s2tMap[charS] != charT)
            {
                // If not, then we have found a conflit mapping
                return false;
            }
        }
        // Check II: if charS has not been mapped to a character in t yet, check if the current charT is already mapped to by another charS
        else if (t2sMap.find(charT) != t2sMap.end())
        {
            // If tChar is already mapped to, check if that charS is the same as the current charS
            if (t2sMap[charT] != charS)
            {
                // If not, then two different charS is mapped to the same charT, which cannot be
                return false;
            }
        }
        else
        {
            // If both checks return false, just add the bidirectional mappings
            s2tMap[charS] = charT;
            t2sMap[charT] = charS;
        }
    }
    return true;
}