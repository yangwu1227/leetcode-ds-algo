// find_winders.cpp
#include "find_winners.hpp"
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

std::vector<std::vector<int>> findWinners(const std::vector<std::vector<int>> &matches)
{
    std::unordered_map<int, int> lossCounts;
    for (const auto &match : matches)
    {
        int winner = match[0], loser = match[1];
        // Ensures winner is in map with zero losses if not already present
        lossCounts.try_emplace(winner, 0);
        lossCounts[loser] += 1;
    }

    std::vector<int> winners, losers;
    winners.reserve(lossCounts.size());
    losers.reserve(lossCounts.size());
    for (const auto &[player, lossCount] : lossCounts)
    {
        // If winner has never lost
        if (lossCount == 0)
        {
            winners.push_back(player);
        }
        // If a loser only lost once
        if (lossCount == 1)
        {
            losers.push_back(player);
        }
    }

    std::sort(begin(winners), end(winners));
    std::sort(begin(losers), end(losers));

    std::vector<std::vector<int>> result = {winners, losers};

    return result;
}
