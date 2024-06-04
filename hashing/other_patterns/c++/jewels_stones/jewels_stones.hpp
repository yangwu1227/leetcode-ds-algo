// jewels_stones.hpp
#ifndef JEWELS_STONES_HPP
#define JEWELS_STONES_HPP
#include <string>

class JewelStones
{
public:
    /**
     * @brief Given two strings `jewewls` and `stones`, return the number of `stones` that are considered `jewels`. This approach uses a hash map to store
     * the counts of `stones`.
     *
     * @param jewewls A sring consisting of lower and upper english letters, representing the unique types of stones that are considered `jewels`
     * @param stones A string consisting of lower and upper english letters, representing the `stones`
     * @return int Number of `stones` that are considered `jewels`
     */
    static int hashmap(const std::string &jewewls, const std::string &stones);

    /**
     * @brief Given two strings `jewewls` and `stones`, return the number of `stones` that are considered `jewels`. This approach uses a set to ensure that checking each `stone`
     * for existence in `jewels` is O(1) average.
     *
     * @param jewewls A sring consisting of lower and upper english letters, representing the unique types of stones that are considered `jewels`
     * @param stones A string consisting of lower and upper english letters, representing the `stones`
     * @return int Number of `stones` that are considered `jewels`
     */
    static int set(const std::string &jewewls, const std::string &stones);
};

#endif