// moving_average.hpp
#ifndef MOVING_AVERAGE_HPP
#define MOVING_AVERAGE_HPP
#include <queue>

class MovingAverage
{
public:
    /**
     * @brief Construct a new Moving Average object.
     *
     * @param windowSize The size of the moving window
     */
    MovingAverage(int windowSize);

    /**
     * @brief Adds a new value to the data stream and returns the current moving average.
     *
     * @param val
     * @return double The new value to add to the data stream
     */
    double next(int val);

private:
    std::queue<int> dataStream; // Used to store data values in the stream
    double runningSum;             // Used to store the running sum of the data stream
    int windowSize;             // The size of the moving window
};

#endif
