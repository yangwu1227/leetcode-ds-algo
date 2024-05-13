// find_winners.hpp
#ifndef FIND_WINNERS_HPP
#define FIND_WINNERS_HPP
#include <vector>

/**
 * @brief Given an integer array `matches` where `matches[i] = [winner_i, loser_i]` indicates that the player `winner_i` defeated player `loser_i` in a match.
 *
 * @param matches vector of vectors where each inner vector contains two integers `winner_i` and `loser_i`
 *
 * @return std::vector<std::vector<int>> A list of two lists where 1) the first list contains the players who never lose once and 2) the second list contains the players who only lost once
 */
std::vector<std::vector<int>> findWinners(const std::vector<std::vector<int>> &matches);

#endif
