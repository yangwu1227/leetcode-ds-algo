// final_prices.cpp
#include "final_prices.hpp"
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

std::vector<int> FinalPrices::hashApproach(const std::vector<int> &prices)
{
    if (prices.size() == 1)
    {
        return prices;
    }

    std::stack<int, std::vector<int>> priceStack;
    std::unordered_map<int, int> nextSmallerMap;
    for (int i = 0; i < prices.size(); i++)
    {
        // While the stack is non-empty and the current prices does not break the monotonic decreasing property
        while (!priceStack.empty() && prices[i] <= prices[priceStack.top()])
        {
            // Pop the elemnt, store the top of the stack index as the key and its next smaller index as the value
            nextSmallerMap[priceStack.top()] = i;
            priceStack.pop();
        }
        priceStack.push(i);
    }

    // Populate the output vector
    std::vector<int> output(prices.size());
    for (int i = 0; i < prices.size(); i++)
    {
        output[i] = nextSmallerMap.find(i) != nextSmallerMap.end() ? prices[i] - prices[nextSmallerMap[i]] : prices[i];
    }

    return output;
}

void FinalPrices::noHashApproach(std::vector<int> &prices)
{
    if (prices.size() == 1)
    {
        return;
    }

    std::stack<int, std::vector<int>> priceStack;
    for (int i = 0; i < prices.size(); i++)
    {
        // While the stack is non-empty and the current prices does not break the monotonic decreasing property
        while (!priceStack.empty() && prices[i] <= prices[priceStack.top()])
        {
            // Pop the elemnt, store the top of the stack index as the key and its next smaller index as the value
            prices[priceStack.top()] -= prices[i];
            priceStack.pop();
        }
        priceStack.push(i);
    }
}
