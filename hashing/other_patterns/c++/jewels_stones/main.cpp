// main.cpp
#include "jewels_stones.hpp"
#include <unordered_map>
#include <string>
#include <cassert>
#include <iostream>

int main()
{
    std::unordered_map<std::string, std::string> testCases = {
        {"aA", "aAAbbbb"},
        {"z", "ZZ"},
        {"yangwu", "yangcpppythonR"}};

    for (const auto &[jewels, stones] : testCases)
    {
        int numJewelsHashMap = JewelStones::hashmap(jewels, stones);
        int numJewelSet = JewelStones::set(jewels, stones);
        assert(numJewelsHashMap == numJewelSet);

        std::cout << "Given jewels = '" << jewels << "' and stones = '" << stones << "', there are " << numJewelSet << " stones that are considered jewels\n";
    }
    std::cout << std::endl;

    return 0;
}