// main.cpp
#include "recent_requests.hpp"
#include "rng_integer.hpp"
#include <iostream>
#include <memory>

int main()
{
    int threshold = generateRandomInteger(500, 3500);
    std::unique_ptr<RecentCounter> recent_counter_ptr = std::make_unique<RecentCounter>(threshold);
    int timeStamp = 0;
    for (int i = 0; i < 10; i++)
    {
        timeStamp += generateRandomInteger(100, 2000);
        std::cout << "There were " << recent_counter_ptr->ping(timeStamp) << " requests within the past " << threshold << " ms window" << '\n';
    }
    std::cout << std::endl;

    return 0;
}
