// stock_spanner.hpp
#ifndef STOCK_SPANNER_HPP
#define STOCK_SPANNER_HPP
#include <stack>
#include <deque>
#include <utility> // std::pair, std::make_pair

class StockSpanner
{
public:
    /**
     * @brief Construct a new Stock Spanner instance.
     *
     */
    StockSpanner();

    /**
     * @brief Calculates the stock span for the given price.
     *
     * @param price The current day's stock price
     * @return int The span of stock prices less than or equal to the current price
     */
    int next(int price);

private:
    // Define a struct to represent the pair of price and span
    struct PriceSpan
    {
        int price;
        int span;
    };

    std::stack<PriceSpan, std::deque<PriceSpan>> stackPriceSpan; // Stack to store PriceSpan structs
};

#endif
