// min_card_pickup.cpp
#include "min_card_pickup.hpp"
#include <unordered_map>
#include <vector>
#include <limits>

int minCardPickup(const std::vector<int> &cards)
{
    std::unordered_map<int, int> cardIndices;
    int minDist = std::numeric_limits<int>::max();
    // O(n) to check and update
    for (int i = 0; i < cards.size(); i++)
    {
        // If the card has already been seen before
        if (cardIndices.find(cards[i]) != cardIndices.end())
        {
            // Compute distance between the the current index and the previous index where 'card' was seen
            int dist = i - cardIndices[cards[i]] + 1;
            // Check to see if we have found a even smaller minimum number of pickups
            minDist = std::min(minDist, dist);
        }
        // Record the index of the most recent occurrence of 'card'
        cardIndices.insert_or_assign(cards[i], i);
    }

    return (minDist < std::numeric_limits<int>::max() ? minDist : -1);
}
