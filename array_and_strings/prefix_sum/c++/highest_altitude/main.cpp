// main.cpp
#include "highest_altitude.hpp"
#include "custom_rng.hpp"
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> gain1 = generateRandomVector(12, -14, 20);
    std::vector<int> gain2 = generateRandomVector(7, -30, 29);
    std::vector<std::vector<int>> testCases = {gain1, gain2};

    for (const auto &gain : testCases)
    {
        int highestPoint = highestAltitude(gain);
        std::cout << "Given the gains vector {";
        for (const auto &value : gain)
        {
            std::cout << value << (&value != &gain.back() ? ", " : "");
        }
        std::cout << "}, the highest point is " << highestPoint << '\n';
    }
    std::cout << std::endl;

    return 0;
}
