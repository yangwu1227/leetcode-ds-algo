// min_card_pickup.hpp
#ifndef MIN_CARD_PICKUP_HPP
#define MIN_CARD_PICKUP_HPP
#include <vector>

/**
 * @brief Given a deck of `cards`, where `cards[i]` represents the value of the `ith` card, a pair of cards are matching
 * if the cards have the same values.
 *
 * @param cards A vector of non-negative integers representing the value of the the `ith` card

 * @return int Minimum number of consecutive cards picked in order to find a pair of matching cards or -1 if it is impossible
 */
int minCardPickup(const std::vector<int> &cards);

#endif
