// recent_requests.cpp
#include "recent_requests.hpp"
#include <queue>

RecentCounter::RecentCounter(int threshold) : internalQueue(), threshold(threshold) {};

int RecentCounter::ping(int t)
{
    // As long as the queue is not empty and the front of the queue is outside of the time window, keep removing these time stamps
    while (!this->internalQueue.empty() && t - internalQueue.front() > this->threshold)
    {
        this->internalQueue.pop();
    }
    this->internalQueue.push(t);
    return this->internalQueue.size();
}
