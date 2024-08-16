// main.cpp
#include "find_winners.hpp"
#include <vector>
#include <iostream>

int main()
{
    std::vector<std::vector<std::vector<int>>> testMatches = {
        {{1, 3}, {2, 3}, {3, 6}, {5, 6}, {5, 7}, {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}},
        {{2, 3}, {1, 3}, {5, 4}, {6, 4}},
        {{2, 3}, {1, 5}, {5, 7}, {6, 4}, {9, 3}, {2, 9}, {4, 9}, {8, 4}}};

    for (const auto &matches : testMatches)
    {
        std::vector<std::vector<int>> result = findWinners(matches);
        std::vector<int> winners = result[0];
        std::vector<int> losers = result[1];
        std::cout << "Given the match results {";
        for (const auto &match : matches)
        {
            std::cout << "{";
            for (const auto &player : match)
            {
                std::cout << player << (&player != &match.back() ? ", " : "");
            }
            std::cout << "}" << (&match != &matches.back() ? ", " : "");
        }
        std::cout << "}, players {";
        for (const auto &winner : winners)
        {
            std::cout << winner << (&winner != &winners.back() ? ", " : "");
        }
        std::cout << "} never lose and players {";
        for (const auto &loser : losers)
        {
            std::cout << loser << (&loser != &losers.back() ? ", " : "");
        }
        std::cout << "} only lost once" << '\n';
    }
    std::cout << std::endl;

    return 0;
}
