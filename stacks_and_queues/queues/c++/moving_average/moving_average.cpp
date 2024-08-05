// moving_average.cpp
#include "moving_average.hpp"
#include <queue>

MovingAverage::MovingAverage(int windowSize) : windowSize(windowSize), runningSum(0), dataStream() {};

double MovingAverage::next(int val)
{
    // If the data stream is filled  up to the window size capacity, subtract the front of the queue from the running sum
    if (this->dataStream.size() == this->windowSize)
    {
        this->runningSum -= this->dataStream.front();
        this->dataStream.pop();
    }
    // Add the new data value to the stream and update the running sum
    this->dataStream.push(val);
    this->runningSum += val;
    double avg = static_cast<double>(this->runningSum) / this->dataStream.size();
    return avg;
}
