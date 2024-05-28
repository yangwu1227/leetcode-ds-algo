// main.cpp
#include "min_card_pickup.hpp"
#include <vector>
#include <iostream>
#include <string>

int main()
{
    std::vector<std::vector<int>> testCards = {
        {3, 4, 2, 3, 4, 7},
        {1, 0, 5, 3},
        {95, 11, 8, 65, 5, 86, 30, 27, 30, 73, 15, 91, 30, 7, 37, 26, 55, 76, 60, 43, 36, 85, 47, 96, 6}};

    for (const auto &cards : testCards)
    {
        int minPickups = minCardPickup(cards);
        std::cout << "Give the input {";
        for (const auto &card : cards)
        {
            std::cout << card << (&card != &cards.back() ? ", " : "");
        }
        std::cout << "}, " << (minPickups != -1 ? "we need a minimum of " + std::to_string(minPickups) + " pickups to find a matching card" : "there is no matching cards") << '\n';
    }
    std::cout << std::endl;

    return 0;
}
