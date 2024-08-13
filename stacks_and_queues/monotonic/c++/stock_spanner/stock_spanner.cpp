// stock_spanner.cpp
#include "stock_spanner.hpp"
#include <stack>
#include <deque>
#include <utility> // std::pair, std::make_pair

StockSpanner::StockSpanner() : stackPriceSpan() {};

int StockSpanner::next(int price)
{
    int span = 1;
    /// While the stack is non-empty and the top of the stack price is lower than the current day price
    while (!this->stackPriceSpan.empty() && this->stackPriceSpan.top().price <= price)
    {
        // Update the span and pop the top pair of (price, span)
        span += this->stackPriceSpan.top().span;
        this->stackPriceSpan.pop();
    }
    // Create a new pair
    PriceSpan currentPriceSpan = {price, span};
    this->stackPriceSpan.push(currentPriceSpan);
    return span;
}
