// main.cpp
#include "moving_average.hpp"
#include "rng_integer.hpp"
#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    int windowSize = generateRandomInteger(1, 6);
    MovingAverage movingAverage = MovingAverage(3);
    for (int i = 0; i < 10; i++)
    {
        int val = generateRandomInteger(std::pow(-10, 5), std::pow(10, 5));
        std::cout << "The moving average is the current window of size = " << windowSize << " is " << movingAverage.next(val) << '\n';
    }
    std::cout << std::endl;
    return 0;
}
