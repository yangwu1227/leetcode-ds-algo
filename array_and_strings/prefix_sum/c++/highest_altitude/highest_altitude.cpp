// highest_altitude.cpp
#include "highest_altitude.hpp"
#include <vector>

int highestAltitude(const std::vector<int> &gain)
{
    // Track running sum and find max point in one go, costing O(n)
    int highestPoint = 0;
    int currentSum = 0;
    for (const auto &value : gain)
    {
        currentSum = currentSum + value;
        highestPoint = std::max(highestPoint, currentSum);
    }

    return highestPoint;
}
