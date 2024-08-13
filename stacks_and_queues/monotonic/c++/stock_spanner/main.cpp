// main.cpp
#include "stock_spanner.hpp"
#include <iostream>
#include <vector>
#include <memory>

int main()
{
    std::vector<std::vector<int>> priceData = {
        {100, 80, 60, 40, 30, 13, 102},
        {17, 88, 91, 100, 124, 43}};

    for (auto const &prices : priceData)
    {
        std::unique_ptr<StockSpanner> stockSpannerPtr = std::make_unique<StockSpanner>();
        for (auto &price : prices)
        {
            std::cout << "The current price is " << price << ", and its span is " << stockSpannerPtr->next(price) << '\n';
        }
        std::cout << std::endl;

    }

    return 0;
}
