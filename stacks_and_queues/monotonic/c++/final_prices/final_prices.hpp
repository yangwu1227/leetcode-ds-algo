// final_prices.hpp
#ifndef FINAL_PRICES_HPP
#define FINAL_PRICES_HPP
#include <vector>

/**
 * @brief Compute the final prices after applying discounts using a deque
 * and a hash map to track the next smaller price.
 *
 * The discount for each item is calculated based on the next item in the
 * sequence that has a price less than or equal to the current item.
 */
class FinalPrices
{
public:
    /**
     * @brief Using an `std::unordered_map` to map each index in `prices` to the index of its next smaller element.
     */
    static std::vector<int> hashApproach(const std::vector<int> &prices);

    /**
     * @brief Modifying the input `std::vector` in place.
     *
     * @param prices
     * @return std::vector<int>
     */
    static void noHashApproach(std::vector<int> &prices);
};

#endif
