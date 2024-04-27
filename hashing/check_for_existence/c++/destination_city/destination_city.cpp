// destination_city.cpp
#include "destination_city.hpp"
#include <vector>
#include <string>
#include <unordered_map>

std::string destCity(const std::vector<std::vector<std::string>> &paths)
{
    std::unordered_map<std::string, int> destCounts;
    // O(n) to build a hash table mapping city name -> count
    for (const auto &path : paths)
    {
        const std::string &dep = path[0];
        const std::string &dest = path[1];

        // Insert a new key-value in place if there is no element with the key
        // The 'result.first' is an iterator pointing to the inserted element
        // The 'result.second' is true if the insertion took place or false if key already exists
        auto result = destCounts.emplace(dep, -1);
        // If the insertion didn't happen
        if (!result.second)
        {
            // Decrement the value (destination count) of a city
            --result.first->second;
        }

        result = destCounts.emplace(dest, 1);
        // If the insertion didn't happen,
        if (!result.second)
        {
            // Increment the value (destination count) of a city
            ++result.first->second;
        }
    }

    for (const auto &entry : destCounts)
    {
        // If the value, i.e., destination count, is > 0
        if (entry.second > 0)
        {
            // Return name of city
            return entry.first;
        }
    }
    // Never gets here if a solution is guaranteed
    return " ";
}
